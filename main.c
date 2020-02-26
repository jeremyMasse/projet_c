#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventaire.h"
int main(void)
{
    struct Item_s *inventaire = initialisation();
    if (inventaire == NULL)
        return(-1);
    add_item(inventaire, "dague");
    add_item(inventaire, "couteau");
    add_item(inventaire, "hache");
    add_item(inventaire, "dzd");
    print_inv(inventaire);
    printf("phase de delete\n");
    del_item(inventaire, "potion");
    del_item(inventaire, "hache");
    del_item(inventaire, "epee");
    print_inv(inventaire);
    printf("phase d'ajout");
    print_inv(inventaire);
    printf("test");
    return 0;
}
