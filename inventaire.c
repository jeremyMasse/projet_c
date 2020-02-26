#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item_s {
    char *nom_item;
    int nbr;
    struct Item_s *next_item;
    struct Item_s *previous_item;
    struct Item_s *head;
    struct Item_s *end;

}Item_t;

struct Item_s *initialisation(void)
{
    struct Item_s *inventaire = malloc(sizeof(struct Item_s));
    if (inventaire == NULL)
        return NULL;
    inventaire->nom_item = "epee";
    inventaire ->nbr = 1;
    inventaire->next_item = NULL;
    inventaire->previous_item = NULL;
    inventaire->head = inventaire;
    inventaire->end = inventaire;

    return inventaire;
}

void print_inv(struct Item_s *inventaire)
{
    inventaire = inventaire->head;
    while (inventaire != NULL){
        printf("Dans l'inventaire il y a : %s\n", inventaire->nom_item);
        inventaire = inventaire->next_item;
    }
}
struct Item_s *add_item(struct Item_s *inventaire, char *nom_item)
{
    for (struct Item_s *i = inventaire->head; i!= NULL; i = i->next_item){
        if((strcmp(nom_item, i->nom_item)) == 0){
           i->nbr = i->nbr + 1;
           return inventaire->head;
        }}
    inventaire->end->next_item = malloc(sizeof(struct Item_s));
    if (inventaire->end->next_item == NULL)
        return NULL;
    inventaire->end->next_item->nom_item = nom_item;
    inventaire->end->next_item->nbr = 1;
    inventaire->end->next_item->next_item = NULL;
    inventaire->end->next_item->head = inventaire->head;
    inventaire->end->next_item->previous_item = inventaire->end;
    inventaire->end = inventaire->end->next_item;
    for (struct Item_s *i = inventaire; i != NULL; i = i->next_item){
        i->end = inventaire->end;
    }
    return inventaire;
}
struct Item_s *del_item(struct Item_s *inventaire, char *nom)
{
    inventaire = inventaire->head;
    while(inventaire->next_item != NULL && strcmp(inventaire->nom_item, nom) != 0){
        inventaire = inventaire->next_item;
    }
    if (inventaire->nbr > 1){
        inventaire->nbr = inventaire->nbr - 1;
        return inventaire->head;
    }

    struct Item_s *tmp = inventaire;
    if (count_item(inventaire) == 1){
        add_item(inventaire, "vide");
    }
    if (inventaire->previous_item != NULL && inventaire->next_item != NULL){
        inventaire->next_item->previous_item = inventaire->previous_item;
        inventaire->previous_item->next_item = inventaire->next_item;
        free(tmp);
        *inventaire = *inventaire->next_item;
    }
    else if (inventaire->previous_item == NULL ){
        inventaire->next_item->previous_item = NULL;
        for (struct Item_s *i = inventaire; i->next_item != NULL; i = i->next_item){
            i->head = inventaire->next_item;
        }
        free(tmp);
        *inventaire = *inventaire->head;
        }
    else if (inventaire->next_item == NULL){
        inventaire->previous_item->next_item = NULL;
        for (struct Item_s *i = inventaire->head; i->next_item != NULL; i = i->next_item){
            i->end = inventaire->previous_item;
        }}
    return inventaire->head;
}
int count_item(struct Item_s *inventaire)
{
    int counter = 0;
    inventaire = inventaire->head;
    while(inventaire != NULL){
        counter = counter + 1;
        inventaire = inventaire->next_item;
    }
    return counter;
}
