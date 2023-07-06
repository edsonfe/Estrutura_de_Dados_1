#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

#ifndef SLLIST_C_INCLUDED
#define SLLIST_C_INCLUDED

#define TRUE 1
#define FALSE 0


SLList *sllCreate(void){
    SLList *l;
    l = (SLList *)malloc(sizeof(SLList));
    if(l != NULL){
        l->first = NULL;
        return l;
    }
}

int sllDestroy(SLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

void *sllQuery(SLList *l, void *key, int(*cmp)(void*, void*)){
    SLNode *spec;
    int stat;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            stat = cmp(spec->data, key);
            while(stat != TRUE && spec->next != NULL){
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if(stat == TRUE){
                data = spec->data;
                return data;
            }
        }
    }
    return NULL;
}

void *sllGetFirst(SLList *l){
    SLNode *first;
    if(l != NULL){
        if(l->first != NULL){
            first = l->first;
            return first->data;
        }
    }
    return NULL;
}

void *sllGetNext(SLList *l, int p){
    SLNode *spec;
    void *next;
    int i = 0;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            while(i < p && spec->next != NULL){
                i++;
                spec = spec->next;
            }
            if(i == p){
                next = spec->data;
                return next;
            }
        }
    }
    return NULL;
}

void *sllGetLast(SLList *l){
    SLNode *last;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            last = l->first;
            while(last->next != NULL){
                last = last->next;
            }
            data = last->data;
            return data;
        }
    }
    return NULL;
}

void *sllRemove(SLList *l, void *key, int (*cmp)(void*, void*)){
    SLNode *spec, *prev;
    void *data;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            prev = NULL;
            stat = cmp(spec->data, key);
            while(stat != TRUE && spec->next != NULL){
                prev = spec;
                spec = spec->next;
                stat = cmp(spec->data, key);
            }
            if(stat == TRUE){
                data = spec->data;
                if(l->first == spec){
                    l->first = spec->next;
                }
                else{
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

void *sllRemoveFirst(SLList *l){
    SLNode *first;
    void *data;
    if(l != NULL){
        if(l->first != NULL){
            first = l->first;
            data = first->data;
            l->first = first->next;
            free(first);
            return data;
        }
    }
    return NULL;
}

void *sllNElms(SLList *l){
    SLNode *last;
    int n = 0;
    if(l != NULL){
        if(l->first != NULL){
            last = l->first;
            while(last->next != NULL){
                n++;
                last = last->next;
            }
            return n;
        }
    }
    return NULL;
}

int sllInsertFirst(SLList *l, void *data){
    SLNode *newnode;
    if(l != NULL){
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int *sllInsertAfterSpec(SLList *l, void *key, int (*cmp)(void*, void*), void *data){
    SLNode *spec, *newnode;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != TRUE){
                spec = spec->next;
                stat = cmp(key, spec->next);
            }
            if(stat == TRUE){
                newnode = (SLNode *)malloc(sizeof(SLNode));
                if(newnode != TRUE){
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
        return FALSE;
    }
}

int *sllInsertPEsimo(SLList *l, int p, void *data){
    SLNode *spec, *newnode;
    int i = 0;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            while(i < p && spec->next != NULL){
                i++;
                spec = spec->next;
            }
            if(i == p){
                newnode = (SLNode *)malloc(sizeof(SLNode));
                if(newnode != NULL){
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int *sllInsertBeforeSpec(SLList *l, void *key, void *data, int (*cmp)(void*, void*)){
    SLNode *spec, *newnode, *prev;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            prev = NULL;
            stat = cmp(key, spec->data);
            while(spec->next != NULL && stat != NULL){
               prev = spec;
               spec = spec->next;
               stat = cmp(key, spec->data);
            }
            if(stat == TRUE){
                newnode = (SLNode*)malloc(sizeof(SLNode));
                if(newnode != NULL){
                    newnode->data = data;
                    newnode->next = spec;
                    if(prev != NULL){
                        prev->next = newnode;
                    }
                    else{
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
        return NULL;
    }
}

int sllRemoveAfterSpec(SLList *l, void *key, int (*cmp)(void*, void*)){
    SLNode *next, *spec;
    void *data;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != NULL){
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if(stat == TRUE){
                next = spec->next;
                if(next != NULL){
                    data = next->data;
                    spec->next = next->next;
                    free(spec);
                    return data;
                }
            }
        }
    }
    return NULL;
}

int QueryTimeGols(void *a, void *b){
    Time *pa;
    int *pb;
    pa = (Time *)a;
    pb = (int *)b;
    if(pa->gols == pb){
        return TRUE;
    }else{
        return FALSE;
    }
}

int QueryTimeMediaGols(void *a, void *b){
    Time *pa;
    float *pb;
    pa = (Time *)a;
    pb = (float *)b;
    if(pa->mediaGols*10 == *pb*10){
        return TRUE;
    }else{
        return FALSE;
    }
}

int QueryTimeNome(void *a, void *b){
    Time *pa;
    char *pb;
    pa = (Time *)a;
    pb = (char *)b;
    if(!strncasecmp(pa->nome, pb, strlen(pa->nome))){
        return TRUE;
    }else{
        return FALSE;
    }
}

#endif // SLLIST_C_INCLUDED
