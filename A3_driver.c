/*
 * CSC A48 - Assignment 3 driver
 * 
 * This driver is *very* different from the ones for A1 and A2.
 * 
 * For the previous 2 assignments, and through the exercises
 * you have solved so far, we have been helping you develop and
 * improve your skills for testing code and verything it is
 * *correct*. 
 * 
 * So, this driver only does the basic functionality of
 * calling the functions that set-up a graph, and shows you
 * how to call the functions that you have to implement.
 * 
 * Defining the tests you have to run on your code, and 
 * determining whether the code is correct, is up to you.
 * 
 * *You will NOT submit this file* - but you obviously want
 * to make sure you run sufficient and thorough testing of
 * all components of your A3 solution to avoid any problems
 * when we auto-mark it.
 * 
 * Suggestions: Test for *correctness*, not output. As we
 * have explained before - you can write code that produces
 * the right output and still is completely wrong in terms of
 * what it does to solve a problem.
 * 
 * So, think carefully about the correctness aspect of your
 * solution, see the post on Piazza on how to test your
 * code (it's old by now, but pinned), and remember your
 * notes for Unit 5 - the section on how to debug recursive
 * code.
 * 
 * (c) 2019 - F. Estrada, M. Ahmadzadeh
 */

#include<stdio.h>
#include<stdlib.h>
#include"ingredient_graph.c"
#include <time.h>

int main()
{
   /*
    * Just a quick demo of how to set up the graph and call
    * the functions you are supposed to implement
    */

    clock_t start, end;
    double cpu_time_used;

    start = clock();
   
   intNode *head=NULL;
   char recipe[10][MAX_STR_LEN]={"fresh breadcrumbs",
				 "artichoke hearts",
				 "quinoa",
				 "",
				 "",
				 "",
				 "",
				 "",
				 "",
				 ""};
   
   // Load the ingredients graph - you control which size
   // you want by commenting/uncommenting the corresponding
   // #define at the top of 'ingredient_graph.c'
   load_ingredients();
   printf("------- The available ingredients should appear above this line -------\n");
   // Call related ingredients
   printf("\n ****** Related ingredients for quinoa:\n");
   related_ingredients("quinoa");  // Make sure this
				   // ingredient exists
   
   printf("\n ****** Related to 'quinoa' k-dist, k=0\n");
   head=related_k_dist(head,"quinoa",0,0);
   print_ingredients(head);
   head=deleteList(head);
 
   printf("\n ****** Related to 'quinoa' k-dist, k=1\n");
   head=related_k_dist(head,"quinoa",1,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'artichoke hearts', k_source=0, k_dest=0;\n");
   head=related_with_restrictions("quinoa","artichoke hearts",0,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=0;\n");
   head=related_with_restrictions("quinoa","tomato juice",2,0);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=2;\n");
   head=related_with_restrictions("quinoa","tomato juice",2,2);
   print_ingredients(head);
   head=deleteList(head);

   printf("\n ****** substituting ingredient 'quinoa' in recipe\n");
   substitute_ingredient(recipe,"quinoa");
   for (int i=0; i<10; i++)
     if (strlen(recipe[i])>0) printf("%s\n",recipe[i]);

   /* The OUTPUT of my solution to this assignment for the sample calls above is:

 ****** Related ingredients for quinoa:
artichoke hearts
sunflower seeds

 ****** Related to 'quinoa' k-dist, k=0
sunflower seeds
artichoke hearts

 ****** Related to 'quinoa' k-dist, k=1
gruyere cheese
turkey
medium shrimp
quinoa
soymilk
sunflower seeds
artichoke hearts

 ****** Related with restrictions, 'quinoa', 'artichoke hearts', k_source=0, k_dest=0;
sunflower seeds

 ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=0;
artichoke hearts
sunflower seeds
soymilk
quinoa
medium shrimp
turkey
gruyere cheese

 ****** Related with restrictions, 'quinoa', 'tomato juice', k_source=2, k_dest=2;
sunflower seeds
soymilk
quinoa
turkey

 ****** substituting ingredient 'quinoa' in recipe
fresh breadcrumbs
artichoke hearts
gruyere cheese

   You can use that as a reference, but BEWARE the fact that though I am confident my
   solution is correct *I have not had the time to thoroughly test it*
   (you should know by now what that means)
   
   */
          
   // Insert ALL of your tests below this line, make sure you test your 
   // code thoroughly.
   // Verify your code's work by checking *on paper* for lists of
   // ingredients your tests ask for!
   // Time to practice those testing skills!

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("program took %f seconds to run\n", cpu_time_used);

  return 0;   
}
