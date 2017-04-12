/*
*
*   Copyright (c) 2017, Red Hat, Inc.
*   Copyright (c) 2017, Masatake YAMATO
*
*   This source code is released for free distribution under the terms of the
*   GNU General Public License version 2 or (at your option) any later version.
*
*   Facility for delayed memory releasing, insptired from AutoreleasePool
*   of OpenStep.
*/

#ifndef CTAGS_MAIN_TRASH_H
#define CTAGS_MAIN_TRASH_H

typedef void (* TrashBoxDestroyItemProc) (void *);
typedef struct sTrashBox TrashBox;

extern TrashBox* trashBoxNew       (void);
extern TrashBox* trashBoxStack     (TrashBox* trash_box);
extern void      trashBoxDelete    (TrashBox* trash_box);
extern void*     trashBoxPut       (TrashBox* trash_box, void* item, TrashBoxDestroyItemProc destroy);
extern TrashBoxDestroyItemProc trashBoxTakeBack  (TrashBox* trash_box, void* item);
extern void      trashBoxFree      (TrashBox* trash_box, void* item);
extern void      trashBoxMakeEmpty (TrashBox* trash_box);

#endif /* CTAGS_MAIN_TRASH_H */
