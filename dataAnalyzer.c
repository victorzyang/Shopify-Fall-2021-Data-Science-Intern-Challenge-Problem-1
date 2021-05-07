#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 500
#define MAX_COL_LEN 100

int main(int argc, char const *argv[]) {
  FILE *fp_text;

  fp_text = fopen("orders.csv", "r"); //opens the file using read mode (“r”)

  if(!fp_text){ //check for errors; if file does not exist
    printf("ERROR: Could not open file\n"); //indicates an error has occured
    return 0;
  }

  double aov; //Average Order Value
  int totalOrderAmount = 0;
  int numOfOrders = 0;

  //TODO: read the first line
  char header[MAX_LINE_LEN];
  fscanf(fp_text, "%[^\n]s", header);
  fscanf(fp_text, "\n");

  while(!feof(fp_text)){ //use a while loop to read through all orders
    numOfOrders++;
    int order_amount;

    char order_amount_char[MAX_COL_LEN];
    order_amount_char[0] = '\0';

    fscanf(fp_text, "%[^\n]s", order_amount_char);
    order_amount = atoi(order_amount_char);

    totalOrderAmount += order_amount;

    fscanf(fp_text, "\n"); //goes to next line
  }

  aov = (double)totalOrderAmount / (double)numOfOrders;

  printf("The total order amount is %d\n", totalOrderAmount);
  printf("The total number of orders is %d\n", numOfOrders);
  printf("The AOV is %f\n", aov);

  fclose(fp_text); //close files when done

  return 0;
}
