#pragma once
#include <map>
#include <mutex>
#include "keyboardmanager/common/KeyboardManagerConstants.h"

#include <common/hooks/LowlevelKeyboardEvent.h>

namespace KeyboardManagerInput
{
    class InputInterface;
}

class KeyboardManagerState;
class Shortcut;
class RemapShortcut;

namespace KeyboardEventHandlers
{
    // Function to a handle a single key remap
    intptr_t HandleSingleKeyRemapEvent(KeyboardManagerInput::InputInterface& ii, LowlevelKeyboardEvent* data, KeyboardManagerState& keyboardManagerState) noexcept;

    /* This feature has not been enabled (code from proof of concept stage)
    * 
    // Function to a change a key's behavior from toggle to modifier
    __declspec(dllexport) intptr_t HandleSingleKeyToggleToModEvent(InputInterface& ii, LowlevelKeyboardEvent* data, KeyboardManagerState& keyboardManagerState) noexcept;
    */

    // Function to a handle a shortcut remap
    intptr_t HandleShortcutRemapEvent(KeyboardManagerInput::InputInterface& ii, LowlevelKeyboardEvent* data, KeyboardManagerState& keyboardManagerState, const std::optional<std::wstring>& activatedApp = std::nullopt) noexcept;

    // Function to a handle an os-level shortcut remap
    intptr_t HandleOSLevelShortcutRemapEvent(KeyboardManagerInput::InputInterface& ii, LowlevelKeyboardEvent* data, KeyboardManagerState& keyboardManagerState) noexcept;

    // Function to a handle an app-specific shortcut remap
    intptr_t HandleAppSpecificShortcutRemapEvent(KeyboardManagerInput::InputInterface& ii, LowlevelKeyboardEvent* data, KeyboardManagerState& keyboardManagerState) noexcept;

    // Function to ensure Num Lock state does not change when it is suppressed by the low level hook
    void SetNumLockToPreviousState(KeyboardManagerInput::InputInterface& ii);

    // Function to ensure Ctrl/Shift/Alt modifier key state is not detected as pressed down by applications which detect keys at a lower level than hooks when it is remapped for scenarios where its required
    void ResetIfModifierKeyForLowerLevelKeyHandlers(KeyboardManagerInput::InputInterface& ii, DWORD key, DWORD target);
};