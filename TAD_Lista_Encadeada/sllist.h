#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
}SLNode;

typedef struct _sllist_ {
    SLNode *first;
}SLList;

typedef struct _time_ {
    char nome[30];
    int gols;
    float mediaGols;
}Time;

SLList *sllCreate(void);
int sllDestroy(SLList *l);
void *sllQuery(SLList *l, void *key, int(*cmp)(void*, void*));
void *sllRemove(SLList *l, void *key, int (*cmp)(void*, void*));
int sllInsertFirst(SLList *l, void *data);
void *sllRemoveFirst(SLList *l);
void *sllGetFirst(SLList *l);
void *sllGetNext(SLList *l, int p);
void *sllGetLast(SLList *l);
void *sllNElms(SLList *l);
int *sllInsertAfterSpec(SLList *l, void *key, int (*cmp)(void*, void*), void *data);
int *sllInsertPEsimo(SLList *l, int p, void *data);
int *sllInsertBeforeSpec(SLList *l, void *key, void *data, int (*cmp)(void*, void*));
int sllRemoveAfterSpec(SLList *l, void *key, int (*cmp)(void*, void*));
int QueryTimeGols(void *a, void *b);
int QueryTimeMediaGols(void *a, void *b);
int QueryTimeNome(void *a, void *b);
#else
extern SLList *sllCreate(void);
extern int sllDestroy(SLList *l);
extern void *sllQuery(SLList *l, void *key, int(*cmp)(void*, void*));
extern void *sllRemove(SLList *l, void *key, int (*cmp)(void*, void*));
extern int sllInsertFirst(SLList *l, void *data);
extern void *sllRemoveFirst(SLList *l);
extern void *sllGetFirst(SLList *l);
extern void *sllGetNext(SLList *l, int p);
extern void *sllGetLast(SLList *l);
extern void *sllNElms(SLList *l);
extern int *sllInsertAfterSpec(SLList *l, void *key, int (*cmp)(void*, void*), void *data);
extern int *sllInsertPEsimo(SLList *l, int p, void *data);
extern int *sllInsertBeforeSpec(SLList *l, void *key, void *data, int (*cmp)(void*, void*));
extern int sllRemoveAfterSpec(SLList *l, void *key, int (*cmp)(void*, void*));
extern int QueryTimeGols(void *a, void *b);
extern int QueryTimeMediaGols(void *a, void *b);
extern int QueryTimeNome(void *a, void *b);

#endif // SLLIST_H_INCLUDED
