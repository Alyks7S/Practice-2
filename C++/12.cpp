#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_NAME_LEN 50
#define MAX_ARTIKUL_LEN 20
#define MAX_PRODUCTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char artikul[MAX_ARTIKUL_LEN];
    float cost;
    float price;
} Product;

void input_product(Product *p) {
    printf("Введите наименование изделия: ");
    scanf("%49s", p->name);
    
    printf("Введите артикул: ");
    scanf("%19s", p->artikul);
    
    printf("Введите себестоимость: ");
    scanf("%f", &p->cost);
    
    printf("Введите цену: ");
    scanf("%f", &p->price);
}

void print_products_table(Product products[], int count) {
    printf("\n| № п/п | Наименование изделия | Артикул | Себестоимость | Цена |\n");
    printf("|-------|----------------------|---------|---------------|------|\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-5d | %-20s | %-7s | %-13.2f | %-4.2f |\n", 
               i+1, 
               products[i].name, 
               products[i].artikul, 
               products[i].cost, 
               products[i].price);
    }
    printf("\n");
}

void find_by_name(Product products[], int count, const char *name) {
    printf("\nРезультаты поиска по наименованию \"%s\":\n", name);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printf("%d. %s (артикул: %s) - себестоимость: %.2f, цена: %.2f\n",
                   i+1, products[i].name, products[i].artikul, products[i].cost, products[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Изделия с таким наименованием не найдены.\n");
    }
}

void find_by_price_range(Product products[], int count, float min_price, float max_price) {
    printf("\nИзделия в ценовом диапазоне от %.2f до %.2f:\n", min_price, max_price);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (products[i].price >= min_price && products[i].price <= max_price) {
            printf("%d. %s (артикул: %s) - себестоимость: %.2f, цена: %.2f\n",
                   i+1, products[i].name, products[i].artikul, products[i].cost, products[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Изделия в указанном ценовом диапазоне не найдены.\n");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); 
    Product products[MAX_PRODUCTS];
    int product_count = 0;
    int choice;
    
    do {
        printf("\nМеню:\n");
        printf("1. Добавить изделие\n");
        printf("2. Вывести ведомость изделий\n");
        printf("3. Поиск по наименованию\n");
        printf("4. Поиск по диапазону цен\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (product_count < MAX_PRODUCTS) {
                    input_product(&products[product_count]);
                    product_count++;
                } else {
                    printf("Достигнуто максимальное количество изделий.\n");
                }
                break;
                
            case 2:
                if (product_count > 0) {
                    print_products_table(products, product_count);
                } else {
                    printf("Нет данных об изделиях.\n");
                }
                break;
                
            case 3: {
                if (product_count > 0) {
                    char search_name[MAX_NAME_LEN];
                    printf("Введите наименование для поиска: ");
                    scanf("%49s", search_name);
                    find_by_name(products, product_count, search_name);
                } else {
                    printf("Нет данных об изделиях.\n");
                }
                break;
            }
                
            case 4: {
                if (product_count > 0) {
                    float min_p, max_p;
                    printf("Введите минимальную цену: ");
                    scanf("%f", &min_p);
                    printf("Введите максимальную цену: ");
                    scanf("%f", &max_p);
                    find_by_price_range(products, product_count, min_p, max_p);
                } else {
                    printf("Нет данных об изделиях.\n");
                }
                break;
            }
                
            case 0:
                printf("Выход из программы.\n");
                break;
                
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);
    
    return 0;
}