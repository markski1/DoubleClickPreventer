# DoubleClickPreventer
Program to prevent broken mouse double clicks on windows. If your mouse is broken and double clicks at random this should help prevent it.

It works by hooking WH_MOUSE_LL and dropping clicks which happen within 100ms of the previous.

Because this is technically a hook there is a non-zero chance of anticheat software false flagging it. It shouldn't happen, it would be tremendously stupid for it to happen.

But if it does, it's not my problem.
