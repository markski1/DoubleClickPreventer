# DoubleClickPreventer
Program to prevent broken mouse double clicks on windows. If your mouse is broken and double clicks at random this should help prevent it.

It works by hooking WH_MOUSE_LL and dropping clicks which happen within 100ms of the previous.

Because this is technically a hook there is a non-zero chance of anticheat software false flagging it. It shouldn't happen, it would be tremendously stupid for it to happen.

But if it does, it's not my problem.

Personal note: I made this program because my Logitech G203 had this issue. While it did considerably improve the situation by stopping clicks from going through twice, there's still other issues asociated with this failure, such as click-dragging acting erratically when selecting files, text or dragging screen elements like windows. While perhaps I could extend this to ignore click-releases that happen too fast (i.e. within 50ms) and other things, I ultimately ended up buying a new mouse.

I still consider this program to be useful at least while you wait for a replacement to arrive. Pull requests are very welcome if you want to expand on any of the above.
