#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void sum();
void who();
void best();
void gender();
void region();
void year();
void average();
void over();
void change();
void newstudent();
void delstudent();

struct Student {
    char name[50];
    char gender;
    int year;
    int month;
    int day;
    char region[50];
    double tests[6];
};

int main() {
    while (1) {
        char input, newLine;
        printf("\nZadaj funkciu: ");
        scanf("%c%c", & input, & newLine);
        if (newLine != '\n') {
            printf("Nespravny vstup\n");
            while (getchar() != '\n');
        } else {
            switch (input) {
            case 's':
                sum();
                break;
            case 'w':
                who();
                break;
            case 'b':
                best();
                break;
            case 'g':
                gender();
                break;
            case 'r':
                region();
                break;
            case 'y':
                year();
                break;
            case 'a':
                average();
                break;
            case 'o':
                over();
                break;
            case 'c':
                change();
                break;
            case 'n':
                newstudent();
                break;
            case 'd':
                delstudent();
                break;
            case 'x':
                return 0;
            default:
                printf("Funkcia nenajdena\n");
                break;
            }
        }
    }
}
void sum() {
    printf("\n");
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                return;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    for (int i = 0; i < records; i++) {
        printf("%s, nar. %d, ", students[i].name, students[i].year);
        if (students[i].gender == 'm')
            printf("muz, Kraj: %s\nVysledky testov: %.2f;%.2f;%.2f;%.2f;%.2f;%.2f", students[i].region, students[i].tests[0], students[i].tests[1], students[i].tests[2], students[i].tests[3], students[i].tests[4], students[i].tests[5]);
        else
            printf("zena, Kraj: %s\nVysledky testov: %.2f;%.2f;%.2f;%.2f;%.2f;%.2f", students[i].region, students[i].tests[0], students[i].tests[1], students[i].tests[2], students[i].tests[3], students[i].tests[4], students[i].tests[5]);
        printf("\n");
    }
    return;
}
void who() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    printf("Zadaj priezvisko: ");
    gets(surname);
    surname[0] = toupper(surname[0]);
    char * key;
    for (int i = 0; i < records; i++) {
        key = strrchr(students[i].name, ' ') + 1;
        if (strcmp(surname, key) == 0) {
            printf("\n%s\nnar. %d, %s\nKraj: %s\n\nVysledky testov: %.2f;%.2f;%.2f;%.2f;%.2f;%.2f\n\n", students[i].name, students[i].year, students[i].gender == 'm' ? "muz" : "zena", students[i].region,
                students[i].tests[0], students[i].tests[1], students[i].tests[2], students[i].tests[3], students[i].tests[4], students[i].tests[5]);

            double max = students[i].tests[0];
            double min = students[i].tests[0];
            double avg = 0;
            for (int j = 0; j < 6; j++) {
                if (students[i].tests[j] >= max)
                    max = students[i].tests[j];
                if (students[i].tests[j] <= min)
                    min = students[i].tests[j];
                avg = avg + students[i].tests[j];
            }
            avg = avg / 6;
            printf("Najlepsi test: %.2f\nNajhorsi test: %.2f\nPriemerny test: %.2f\n", max, min, avg);
            fflush(stdin);
            return;
        }
    }
    printf("Student nenajdeny.\n");
    fflush(stdin);
    return;
}
void best() {
    printf("\n");
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    int id, tid;
    double max = students[0].tests[0];
    for (int i = 0; i < records; i++) {
        for (int j = 0; j < 6; j++) {
            if (students[i].tests[j] >= max) {
                max = students[i].tests[j];
                id = i;
                tid = j + 1;
            }
        }
    }
    printf("Najlepsi test: %.2f\nStudent: %s\nCislo testu: %d\n", max, students[id].name, tid);
    return;
}
void gender() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    char g;
    int id, tid;

    printf("Zadaj pohlavie(m/f): ");
    scanf("%c", & g);
    g = tolower(g);
    if (g == 'm' || g == 'f') {
        double max = 0;
        for (int i = 0; i < records; i++) {
            for (int j = 0; j < 6; j++) {
                if (students[i].tests[j] >= max && students[i].gender == g) {
                    max = students[i].tests[j];
                    id = i;
                    tid = j + 1;
                }
            }
        }
        printf("\nNajlepsi test: %.2f\nStudent: %s\nCislo testu: %d\n", max, students[id].name, tid);
        fflush(stdin);
        return;
    } else {
        printf("Nespravny vstup!\n");
        fflush(stdin);
        return;
    }
}
void region() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    int count = 0, id, tid;
    double max = 0;
    char * regions[8] = {
        "bratislavsky",
        "trnavsky",
        "trenciansky",
        "nitriansky",
        "zilinsky",
        "banskobystricky",
        "presovsky",
        "kosicky"
    };
    char region[20];

    for (int h = 0; h < 8; h++) {
        strcpy(region, regions[h]);
        for (int i = 0; i < records; i++) {
            for (int j = 0; j < 6; j++) {
                if (strcmp(students[i].region, region) == 0 && students[i].tests[j] >= max) {
                    max = students[i].tests[j];
                    id = i;
                    tid = j + 1;
                    count++;
                }
            }
        }
        if (count > 0)
            printf("\nKraj: %s\nNajlepsi test: %.2f\nStudent: %s\nCislo testu: %d\n", region, max, students[id].name, tid);

        max = 0;
        id = 0;
        tid = 0;
        count = 0;
    }
    return;
}
void year() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    int y, id, tid;
    printf("Zadaj rok(YYYY): ");
    scanf("%d", & y);
    if (y > 2022) {
        printf("Nespravny vstup!\n");
        fflush(stdin);
        return;
    } else if (y == 0) {
        printf("Nespravny vstup!\n");
        fflush(stdin);
        return;
    }
    double max = 0;
    for (int i = 0; i < records; i++) {
        for (int j = 0; j < 6; j++) {
            if (students[i].tests[j] >= max && students[i].year > y) {
                max = students[i].tests[j];
                id = i;
                tid = j;
            }
        }
    }
    printf("\n%s\nnar. %d\nNajlepsi test: %.2f\nCislo testu: %d\n", students[id].name, students[id].year, students[id].tests[tid], tid + 1);
    fflush(stdin);
    return;
}
void average() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    int id;
    double avg = 0, bavg = 0;
    printf("\n");
    for (int i = 0; i < records; i++) {
        avg = 0;
        for (int j = 0; j < 6; j++) {
            avg = avg + students[i].tests[j];
        }
        avg = avg / 6;
        printf("%s - %.2f\n", students[i].name, avg);
        if (avg > bavg) {
            bavg = avg;
            id = i;
        }
    }
    printf("\nNajlepsie:\n\n%s - %.2f\n", students[id].name, bavg);
    return;
}
void over() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    double res = 0.00;
    int count = 0, tid;
    char prompt[20];
    printf("Zadaj vysledok testu(realne cislo): ");
    scanf("%lf", & res);
    printf("\n");
    if (res > 100) {
        printf("Nespravny vstup!\n");
        fflush(stdin);
        return;
    }
    for (int i = 0; i < records; i++) {
        for (int j = 0; j < 6; j++) {
            if (students[i].tests[j] >= res)
                count++;
        }
        if (count == 1)
            strcpy(prompt, "test");
        else if (count > 4 || count == 0)
            strcpy(prompt, "testov");
        else
            strcpy(prompt, "testy");
        printf("%s - %d %s", students[i].name, count, prompt);
        for (int k = 0; k < 6; k++) {
            if (students[i].tests[k] >= res) {
                printf(", %d (%.2f)", k + 1, students[i].tests[k]);
            }
        }
        printf("\n");
        count = 0;
    }
    fflush(stdin);
    return;
}
void change() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    char idSurname[30];
    double newResult;
    int id = -1, tid;
    FILE * tempfile;
    tempfile = fopen("____temp.csv", "w");
    printf("Zadaj priezvisko, poradove cislo testu, novy vysledok: ");
    scanf("%s %d %lf", & idSurname, & tid, & newResult);
    idSurname[0] = toupper(idSurname[0]);
    for (int j = 0; j < records; j++) {
        if (strcmp((strrchr(students[j].name, ' ') + 1), idSurname) == 0)
            id = j;
    }
    for (int i = 0; i < records; i++) {
        if (i != id) {
            fprintf(tempfile, "%s;%c;%d/%d/%d;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", students[i].name, students[i].gender, students[i].year, students[i].month, students[i].day, students[i].region, students[i].tests[0], students[i].tests[1], students[i].tests[2], students[i].tests[3], students[i].tests[4], students[i].tests[5]);
        } else if (i == id) {
            for (int k = 0; k < 6; k++) {
                if (k + 1 == tid)
                    students[i].tests[k] = newResult;
            }
            fprintf(tempfile, "%s;%c;%d/%d/%d;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", students[i].name, students[i].gender, students[i].year, students[i].month, students[i].day, students[i].region, students[i].tests[0], students[i].tests[1], students[i].tests[2], students[i].tests[3], students[i].tests[4], students[i].tests[5]);
        }
        if (i != (records - 1))
            fprintf(tempfile, "\n");
    }
    fclose(tempfile);
    if (id == -1)
        printf("Student nenajdeny!");

    remove("studenti.csv");
    rename("____temp.csv", "studenti.csv");
    fflush(stdin);
    sum();
    return;
}
void newstudent() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    FILE * filei;
    filei = fopen("studenti.csv", "a");
    char name[50];
    int chid = -1;
    char gender[5];
    int date[3];
    int con = 0, count = 0;
    char region[20];
    char * regions[8] = {
        "bratislavsky",
        "trnavsky",
        "trenciansky",
        "nitriansky",
        "zilinsky",
        "banskobystricky",
        "presovsky",
        "kosicky"
    };
    double tests[6];
    do
    {
    printf("Zadaj meno a priezvisko: ");
    scanf("%49[^\n]", name);
    name[0] = toupper(name[0]);
    for(int i = 0; i <= strlen(name); i++)
  	{
  		if(name[i] == ' ')  
		{
  			chid = i+1;	
 		}
	}
    name[chid] = toupper(name[chid]);
    for (int i = 0; i < records; i++)
    {
        if(strcmp(students[i].name,name) == 0){
            con = 1;
            printf("Student uz existuje!\n");
            break;
        }
        else
            con = 0;
    }
    fflush(stdin);
    } while (con != 0);
    fprintf(filei, "\n%s;", name);
    do {
        printf("Zadaj datum narodenia (YYYY/MM/DD): ");
        scanf("%d/%d/%d", & date[0], & date[1], & date[2]);
        if (date[0] < 1940 || date[0] > 2005 || date[1] > 12 || date[1] < 1 || date[2] > 31 || date[2] < 1 )
            printf("Nespravny datum!\n");
        else
            con = 1;
    } while (con != 1);
    do {
        printf("Zadaj pohlavie (m/f): ");
        scanf("%s", & gender);
        if (strcmp(gender, "f") == 0 || strcmp(gender, "m") == 0)
            con = 0;
        else
            printf("Nespravny format!\n");
    } while (con != 0);
    do {
        printf("Zadaj kraj: ");
        scanf("%s", & region);
        for (int i = 0; i < 8; i++) {
            if (strcmp(region, regions[i]) == 0)
                con = 1;
        }
        if (con == 0)
            printf("Nespravny vstup!\n");
    } while (con != 1);
  
    printf("Zadaj vysledky 6. testov oddelenych ; : ");
    scanf("%lf;%lf;%lf;%lf;%lf;%lf", & tests[0], & tests[1], & tests[2], & tests[3], & tests[4], & tests[5]);
    fprintf(filei, "%s;%d/%d/%d;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", gender, date[0], date[1], date[2], region, tests[0], tests[1], tests[2], tests[3], tests[4], tests[5]);
    fclose(filei);
    sum();
    fflush(stdin);
    return;
}
void delstudent() {
    FILE * file;
    file = fopen("studenti.csv", "r");
    struct Student students[100];
    int rows = 0, records = 0;
    char surname[30];
    if (file != NULL) {
        do {
             
            rows = fscanf(file,
                "%49[^;];%c;%d/%d/%d;%49[^;];%lf;%lf;%lf;%lf;%lf;%lf\n",
                students[records].name, &
                students[records].gender, &
                students[records].year, &
                students[records].month, &
                students[records].day,
                students[records].region, &
                students[records].tests[0], &
                students[records].tests[1], &
                students[records].tests[2], &
                students[records].tests[3], &
                students[records].tests[4], &
                students[records].tests[5]
            );
            if (rows == 12) records++;

            if (rows != 12 && !feof(file)) {
                printf("Subor nieje mozne precitat.\n");
                break;
            }

        } while (!feof(file));
        fclose(file);
    } else
        printf("Nepodarilo sa otvorit subor.");

    char delSurname[30];
    int id = -1;
    FILE * tempfile;
    tempfile = fopen("____temp.csv", "w");
    printf("Zadaj priezvisko: ");
    gets(delSurname);
    delSurname[0] = toupper(delSurname[0]);
    for (int j = 0; j < records; j++) {
        if (strcmp((strrchr(students[j].name, ' ') + 1), delSurname) == 0) {
            id = j;
        }
    }
    for (int i = 0; i < records; i++) {
        if (i != id) {
            fprintf(tempfile, "%s;%c;%d/%d/%d;%s;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f", students[i].name, students[i].gender, students[i].year, students[i].month, students[i].day, students[i].region, students[i].tests[0], students[i].tests[1], students[i].tests[2], students[i].tests[3], students[i].tests[4], students[i].tests[5]);
        if (i != (records - 1) && i+1 != id)
            fprintf(tempfile, "\n");
        }
    }
    fclose(tempfile);
    if (id != -1)
        printf("\nStudent s menom \"%s\" bol vymazany.\n", students[id].name);
    else
        printf("Student nenajdeny!");

    remove("studenti.csv");
    rename("____temp.csv", "studenti.csv");
    fflush(stdin);
    return;
}