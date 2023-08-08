#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char prizvyshche[32];
    char imya[32];
    char patronymic[32];
    int prog;
    int sda;
    int matan;
    int linal;
} student;

int file_to_struc (student *stud, int num)
{
    FILE *fl;
    fl=fopen("kv13.txt","r");
    if (fl == NULL)
    {
        printf("could not open the file\n");
        return 1;
    }
    int i=0;
    while ((i < num)&&(fscanf(fl, "%s %s %s %d %d %d %d", stud[i].prizvyshche, stud[i].imya, stud[i].patronymic, &(stud[i].prog), &(stud[i].sda), &(stud[i].matan), &(stud[i].linal))!=EOF))
    {
        i++;
    }
    fclose(fl);
}

void output_struc(student *stud, int num)
{
    for (int i=0;i<29;i++)
    {
        printf ("%s %s %s %d %d %d %d\n",
                stud[i].prizvyshche,
                stud[i].imya,
                stud[i].patronymic,
                stud[i].prog,
                stud[i].sda,
                stud[i].matan,
                stud[i].linal);
    }

}

void mid_subj(student *stud, const int num, float *holder, int subnum)
{
    for (int i=0; i<num; i++)
    {
        holder[0]+=stud[i].prog;
        holder[1]+=stud[i].sda;
        holder[2]+=stud[i].matan;
        holder[3]+=stud[i].linal;
    }
        holder[0]/=num;
        holder[1]/=num;
        holder[2]/=num;
        holder[3]/=num;
        printf("Prog - %5.2f, SDA - %5.2f, MatAnaliz - %5.2f, Linal - %5.2f\n",holder[0],holder[1],holder[2],holder[3]);
}

int sub_min (int *mids, int subnum)
{
    int ind_min=0;
    for (int i=1; i<subnum; i++)
    {
        if (mids[i]<mids[ind_min])
        {
            ind_min=i;
        }
    }
    return ind_min;
}

int sub_max (int *mids, int subnum)
{
    int ind_max=0;
    for (int i=1; i<subnum; i++)
    {
        if (mids[i]>mids[ind_max])
        {
            ind_max=i;
        }
    }
    return ind_max;
}

void out_fin (int ind, char type[], float *mids)
{
    switch(ind)
    {
    case 0:
    {
        printf ("%s bal z predmetu Programyvannya: %f\n", type, mids[ind]);
        break;
    }
    case 1:
    {
        printf ("%s bal z predmetu SDA: %f\n", type, mids[ind]);
        break;
    }
    case 2:
    {
        printf ("%s bal z predmetu MatAnaliz: %f\n", type, mids[ind]);
        break;
    }
    case 3:
    {
        printf ("%s bal z predmetu LinAl: %f\n", type, mids[ind]);
        break;
    }
    default:
        {
            printf ("There is an error...(\n");
        }
    }
}

int main()
{
    int group=29;
    student kv13[group];
    printf("Vvedennya danyx studentiv...\n\n");
    file_to_struc (&kv13[0],group);
    printf("Vyvedennya otsinok studentiv:\n");
    output_struc(&kv13[0],group);
    printf("\n\nSeredni baly\n");
    int subj=4;
    float mid_sub[subj];
    mid_subj (&kv13[0],group, &mid_sub[0], subj);
    printf("\nPoshuk naivyshchoho i nainyzhchoho serednoho balu\n");
    int s_max=sub_max(&mid_sub[0], subj);
    out_fin (s_max, "Max",&mid_sub[0]);
    int s_min=sub_min(&mid_sub[0], subj);
    out_fin (s_min, "Min",&mid_sub[0]);
    return 0;
}
