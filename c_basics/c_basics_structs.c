// app file name: c_basics_structs.c
// This app illustrates structs (data structures) in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[50];
  char id[10];
  int age;
  int grades[5];
} Student;

typedef struct
{
  int x;
  int y;
} Point;

typedef struct    // Declare a struct with a pointer array as a member.
{
  int *array;
} Data;

void print_student(Student student);

void print_points(Point points[]); // Pass as many points as are in the
                                   // struct to the function to be printed.
// Main function.
int main(void)
{
  Student kevin;

  // Once an instance of a struct has been named, the values of its non-pointer
  // components are referred to with the .<member_name> syntax[].  For example:
  kevin.age = 16;
  printf("Age: %d\n", kevin.age);

  // Strings (character arrays) get populated like this:
  strcpy(kevin.name, "Kevin");
  strcpy(kevin.id, "000F123");

  // Numeric arrays get populated like this:
  kevin.grades[0] = 3;
  kevin.grades[1] = 4;
  kevin.grades[2] = 4;
  kevin.grades[3] = 3;
  kevin.grades[4] = 4;

  print_student(kevin);

  printf("\n"); // Print blank line.

  Point p1 = {5, 10};

  Point p2 = { .x = 2, .y = 8};

  printf("p1.x: %d\n", p1.x);
  printf("p1.y: %d\n", p1.y);

  printf("\n"); // Print blank line.

  printf("p2.x: %d\n", p2.x);
  printf("p2.y: %d\n", p2.y);

  printf("\n"); // Print blank line.

  p1 = p2;

  printf("p1.x: %d\n", p1.x);
  printf("p1.y: %d\n", p1.y);

  printf("\n"); // Print blank line.

  Point points[10];

  for (int i = 0; i < 10; i++)
    {
      points[i].x = 1;
      points[i].y = 10 - i;
    }

    print_points(points);

    printf("\n"); // Print blank line.

    Data x; // Instiate two Data structs (with a member of pointer arrays
    Data y; // named x and y.

    x.array = malloc( sizeof(int) * 5 ); // Dyanmically allocate space for five
    y.array = malloc( sizeof(int) * 5 ); // integers for each array, which will
                                         // hold five memory addresses. 'array'
    // Populate both arrays:             // will be a pointer to that five
    x.array[0] = 1;                      // address memory space.
    x.array[1] = 2;
    x.array[2] = 3;
    x.array[3] = 4;
    x.array[4] = 5;
    y.array[0] = 9;
    y.array[1] = 9;
    y.array[2] = 9;
    y.array[3] = 9;
    y.array[4] = 9;

    x = y;  // Remember, x an y are arrays of +pointers+, so what will get
            // assigned to x are the memory addresses of the five 9s, not the
            // nines themselves. (This is described as a "memory copy
            // operation.")

    for (int i = 0; i < 5; i++)
      printf("x.array[%d]: %d\n", i, x.array[i]);

    printf("\n"); // Print blank line.

  // Because x is now pointing at the memory address of the values in y, if we
  // modify the value of x.array[], it actually changes the value of y.array[].
  // We show this here:
  x.array[0] = 11; // Change the value that a memory pointer in x points to...

  for (int i = 0; i < 5; i++) // ...and look how the values of y have changed.
    printf("y.array[%d]: %d\n", i, y.array[i]);

  // free(x.array); // I'm getting an error message saying that the pointer
  // free(y.array); // being freed was not allocated, and that I should set a
                    // breakpoint in malloc_error_break to debug.

  return 0;
}

void print_student(Student student)
{
printf("Name: %s\n", student.name);
printf("ID: %s\n", student.id);
printf("Age: %d\n", student.age);
for (int i = 0; i < 5; i++)
  printf("Grade class %d: %d\n", i + 1, student.grades[i]);
}

void print_points(Point points[])
{
  for (int i = 0; i < 10; i++)
    printf("Point[%d]: (%d, %d)\n", i, points[i].x, points[i].y);
}
