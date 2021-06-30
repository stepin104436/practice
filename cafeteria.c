#include<stdio.h>
#include<stdarg.h>              //header file related to variable number of arguments
#include "cafeteria.h"
#define max_rating 10
#define no_students_survey 40
float overall_rating(int count,...)    //helps to take variable number of arguments
{
    int i=0;
    int frequency_array[10]={};   //To know the no of students given a particular scale
    int rating_array[40]={};     //To store individual ratings given by the 40 students
    int total_rating=0;          // A variable to store the total rating given 40 students
    float average_rating=0;     //Variable to store average overall rating of cafeteria
    va_list lst;                //variable of va_list defined in stdarg.h header file
    va_start(lst,count);        // va_start is a macro to intialize va_list
    for(i=0;i<count;i++)
    {
         rating_array[i]=va_arg(lst,int);   //va_arg
         while(rating_array[i]<1||rating_array[i]>max_rating)
         {
             printf("Please enter the cafeteria rating in between 1 and 10: ");
             scanf("%d",&rating_array[i]);
         }
         total_rating+=rating_array[i];

    }
    average_rating=total_rating/40.0;
    for(int c=1;c<=max_rating;c++)
   {
       int a=0;
       for(int r=0;r<no_students_survey;r++)
       {

           if(c==rating_array[r])
           {
               a++;
               int d=c-1;
               frequency_array[d]=a;
           }
       }
   }
    for(int i=0;i<no_students_survey;i++)
     {
         int k=i+1;
         printf("Student no. %d rated the cafeteria as: %d/10\n",k,rating_array[i]);
     }
   printf("The Poll Results according to rating given by students are :\n\n");
   printf(" Rating Scale \t No of Students Polled\n\n");
    for(int n=0;n<max_rating;n++)
    {
        int b=n+1;
        if(frequency_array[n]>=1 || frequency_array[n]<=max_rating)
        {
        printf("    %d \t\t\t %d \n",b,frequency_array[n]);
        }

    }
    printf("\n\n");
    printf("The Cafeteria rating is %.1f\n\n",average_rating);
    va_end(lst);        //va_end is to clean up the memory assigned to va_list variables
    return average_rating;

}
