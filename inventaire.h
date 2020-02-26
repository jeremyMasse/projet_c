#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED


struct Item_s *initialisation(void);
void print_inv(struct Item_s *inventaire);
int count_item(struct Item_s *inventaire);
struct Item_s *add_item(struct Item_s *inventaire, char *nom_item);
struct Item_s *del_item(struct Item_s *inventaire, char *nom);

#endif // INVENTAIRE_H_INCLUDED
