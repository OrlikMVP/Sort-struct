#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _EMPLOYEE {
    int id;
    char name[20];
    char department[20];
    double salary;
    double scores;
} EMPLOYEE, *PEMPLOYEE;

#define MAX_EMPLOYEE_COUNT 10

EMPLOYEE employee[MAX_EMPLOYEE_COUNT];

void get_employee(PEMPLOYEE);
void sort_employee(PEMPLOYEE, int, int (*)(PEMPLOYEE, PEMPLOYEE));
void sort_employee2(PEMPLOYEE, int, int (*)(PEMPLOYEE, PEMPLOYEE));
void sort_employee3(PEMPLOYEE, int, int (*)(PEMPLOYEE, PEMPLOYEE));
void print_employee(PEMPLOYEE, int);

int sort_by_salary(PEMPLOYEE, PEMPLOYEE);
int sort_by_scores(PEMPLOYEE, PEMPLOYEE);
int sort_by_name(PEMPLOYEE, PEMPLOYEE);
int main()
{
    int count = 0;

    printf("id name department salary scores\n");
    do {
      get_employee(&employee[count]);

      char c = getchar();

      if ('Z' == toupper(c)) {
        break;
      } else if ('Q' == toupper(c)) {
          return -1;
      }
      ++count;
    }while(count <= MAX_EMPLOYEE_COUNT);

    printf("\nEntered records %d\n", count);
    print_employee(employee, count);
    printf("\nSort by scores \n");
    sort_employee(employee, count, sort_by_scores);
    print_employee(employee, count);
    printf("\nSort by salary \n");
    sort_employee2(employee,  count, sort_by_salary);
    print_employee(employee, count);
    printf("\nSort by name \n");
    sort_employee3(employee,  count, sort_by_name);
    print_employee(employee, count);

    return 0;
}

void get_employee(PEMPLOYEE pemp) {
    scanf("%d %s %s %lf %lf",
          &(pemp->id),
          pemp->name,
          pemp->department,
          &(pemp->salary),
          &(pemp->scores)
          );
}

void print_employee(PEMPLOYEE pemp, int count) {
    printf("================================\n");
    for (int i = 0; i < count; ++i) {
        EMPLOYEE emp = pemp[i];
        printf("%d %s %s %.3f %.2f\n",
               emp.id,
               emp.name,
               emp.department,
               emp.salary,
               emp.scores
               );
    }
    printf("================================\n");
}

void swap(PEMPLOYEE p1, PEMPLOYEE p2) {
    EMPLOYEE temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int sort_by_scores(PEMPLOYEE p1, PEMPLOYEE p2) {
    if (p1->scores < p2->scores) {
        return -1;
    } else if (p1->scores > p2->scores) {
        return 1;
    } else {
        return 0;
    }
}

void sort_employee(PEMPLOYEE pemp, int count, int (*cmp)(PEMPLOYEE, PEMPLOYEE)) {
  for (int i = 0; i < count - 1; ++i) {
    for (int j = i + 1; j < count; ++j) {
        if (cmp(&pemp[i], &pemp[j]) > 0) {
            swap(&pemp[i], &pemp[j]);
        }
    }
  }
}
int sort_by_salary(PEMPLOYEE p1, PEMPLOYEE p2) {
    if (p1->salary < p2->salary) {
        return -1;
    } else if (p1->salary > p2->salary) {
        return 1;
    } else {
        return 0;
    }
}
void sort_employee2(PEMPLOYEE pemp, int salary, int (*cmp)(PEMPLOYEE, PEMPLOYEE)) {
  for (int i = 0; i < salary - 1; ++i) {
    for (int j = i + 1; j < salary; ++j) {
        if (cmp(&pemp[i], &pemp[j]) > 0) {
            swap(&pemp[i], &pemp[j]);
        }
    }
  }
}
//////////////////////////////////////////

int sort_by_name(PEMPLOYEE p1, PEMPLOYEE p2) {
    if (p1->name[1] < p2->name[1]) {
        return -1;
    } else if (p1->name[1] > p2->name[1]) {
        return 1;
    } else {
        return 0;
    }
}
void sort_employee3(PEMPLOYEE pemp, int name, int (*cmp)(PEMPLOYEE, PEMPLOYEE)) {
  for (char i = 0; i < name - 1; ++i) {
    for (int j = i + 1; j < name; ++j) {
        if (cmp(&pemp[i], &pemp[j]) > 0) {
            swap(&pemp[i], &pemp[j]);
        }
    }
  }
}
