#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

typedef struct node
{
    int pnr;
    char trainname[50];
    char date[12];
    int quota;
    char pa_name[50];
    int age;
    float seat;
    char coach[2];
    float fare;
    struct node *next;
} TICKET;
TICKET *head = NULL;

void insert(TICKET *temp)
{
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        TICKET *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void printBookings(TICKET *ticket)
{
    TICKET *p = head;
    while (p != NULL)
    {
        printf("\n");
        printf("pnr:%d\n", p->pnr);
        printf("passnger name:%s\n", p->pa_name);
        printf("fare:%f\n", p->fare);
        p = p->next;
    }
}

void SearchBookingByTrainType(TICKET *ticket, char *train)
{
    if (ticket != NULL)
    {
        if (strcmp(ticket->trainname, train) == 0)
        {
            printf("\n");
            printf("pnr:%d\n", ticket->pnr);
            printf("pnr:%s\n", ticket->pa_name);
            printf("fare:%f\n", ticket->fare);
        }
        SearchBookingByTrainType(ticket->next, train);
    }
}

void UpdateFares(TICKET *ticket)
{
    float con, sum1 = 0;
    while (ticket != NULL)
    {
        if (ticket->age < 18)
        {
            con = 0.25 * ticket->fare;
        }
        else if (ticket->age >= 18 && ticket->age <= 59)
        {
            con = 0;
        }
        else
        {
            con = 0.5 * ticket->fare;
        }
        ticket->fare = ticket->fare - con;
        printf("\n booking details:\n");
        printf("pnr:%d\n", ticket->pnr);
        printf("pnr:%s\n", ticket->pa_name);
        printf("fare:%f\n", ticket->fare);
        sum1 = sum1 + ticket->fare;
        ticket = ticket->next;
    }
    printf("the sum1 of the fares of all tickets is %f", sum1);
}

TICKET *insertItem(TICKET *item, FILE *fp);
TICKET *genBookingDataset(FILE *fp)
{
    TICKET *ptr;
    TICKET *ptr1;
    ptr = (TICKET *)malloc(sizeof(TICKET));
    ptr1 = insertItem(ptr, fp);

    return ptr1;
}

TICKET *insertItem(TICKET *item, FILE *fp)
{

    char *pen;
    pen = (char *)malloc(50 * sizeof(char));
    char c;
    int i = 0;
    int n = 0;
    c = fgetc(fp);
    while (c != '\n')
    {
        while (c != ',')
        {
            if (c == '\n')
                break;
            if (c == ' ')
            {
                c = fgetc(fp);
                continue;
            }
            if (feof(fp) != 0)
                return item;

            pen[i] = c;
            i++;
            c = fgetc(fp);
        }

        switch (n)
        {
        case 0:
            item->pnr = atoi(pen);
            break;
        case 1:
            sprintf(item->trainname, "%s", pen);
            break;
        case 2:
            sprintf(item->date, "%s", pen);
            break;
        case 3:
            item->quota = atoi(pen);
            break;
        case 4:
            sprintf(item->pa_name, "%s", pen);
            break;
        case 5:
            item->age = atoi(pen);
            break;
        case 6:
            item->seat = atof(pen);
            break;
        case 7:
            sprintf(item->coach, "%s", pen);
            break;
        case 8:
            item->fare = atof(pen);
            break;
        }
        if (c == '\n')
            break;
        n++;
        i = 0;
        free(pen);
        pen = (char *)malloc(50 * sizeof(char));
        c = fgetc(fp);
    }
    return item;
}

int main()
{
    FILE *fp;
    int flg = 0;
    TICKET *ptr;
    fp = fopen("input.txt", "r");
    while (feof(fp) == 0)
    {
        if (flg == 0)
        {
            head = genBookingDataset(fp);
            ptr = head;
        }
        else if (flg == 14)
        {
            ptr->next = genBookingDataset(fp);
            ptr = ptr->next;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = genBookingDataset(fp);
            ptr = ptr->next;
        }
        flg++;
    }
    fclose(fp);
    char train[50];
    printBookings(head);
    printf("\nEnter the train name to be searched : ");
    scanf("%s", train);
    SearchBookingByTrainType(head, train);
}
