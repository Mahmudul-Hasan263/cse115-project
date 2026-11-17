#include<stdio.h>
//Global Variables//

int fill_up,previous_odometer,current_odometer,distance;
double litres,price,mileage,cost;

//*Accumulators for Running Totals *//
int total_fill_ups=0;
int total_distance=0;
double total_litres=0.0;
double total_cost=0.0;
double total_mileage=0.0;

//* Variables for Best & Worst Tracking*//
double best_mileage=0.0;
double worst_mileage=0.0;

//Functioin protype//

void display_banner(void);
void display_menu(void);
void read_record(void);
void calculate_current(void);
void totals(void);
void print_current_record(void);
void print_final_report(void);
void print_best_worst(void);
void print_cost_per_km(void);


//*Prints the program banner*//
void display_banner(void){
printf("------------------------------------------------------------------\n");
printf("             VEHICLE FUEL AND MILEAGE CHECKING SYSTEM            \n");
printf("------------------------------------------------------------------\n");
}

//* Displays the menu options to the* //

void display_menu(void){
printf("=============================MENU================================\n");
printf(" 1. Log a new fill-up\n");
printf(" 2. View Overall Mileage Report\n");
printf(" 3. View Best and Worst Tank (So far)\n");
printf(" 4. View Overall Cost per Kilometre\n");
printf(" 0. Exit System\n");
printf("=================================================================\n");
}

// *Reads data from the user and validates it using do-while loops*//
void read_record(void) {
printf(" Enter fill-up number\t\t:\t ");
scanf("%d",&fill_up);
printf(" Enter previous odometer(km)\t:\t");
scanf("%d",&previous_odometer);

 //*Odometer Validation: Current odometer cannot be less than previous*//
do {
    printf(" Enter current odometer(km)\t:\t");
    scanf("%d",&current_odometer);
    if (current_odometer<previous_odometer){
    printf("Error\n");
    }
    } while(current_odometer<previous_odometer);

    //* Litres Validation: Fuel must be greater than 0*//
    do {
    printf(" Enter fuel added(litres)\t:\t");
    scanf("%lf", &litres);
    if(litres<= 0){
    printf("Error\n");
}
    } while (litres <= 0);
    //* Litres Validation: Fuel must be greater than 0*//
     do{
        printf(" Enter price per litre\t\t:\t");
        scanf("%lf",&price);
        if (price <= 0){
            printf("Error\n");
        }
    } while (price<=0);
    }
    // *Calculates distance, mileage, and cost for the current record*//
void calculate_current(void){
    distance=current_odometer-previous_odometer;
    mileage=(double)distance/litres;
    cost=litres * price;}

//* Updates total sums and tracks the best/worst mileage*//
void update_totals(void) {
    total_fill_ups++;
    total_distance+=distance;
    total_litres+=litres;
    total_cost+=cost;
    total_mileage+=mileage;

        // Best & Worst Mileage Update Logic//
if (total_fill_ups == 1) {
        // If it's the first record, it is currently both the best and worst//
best_mileage = mileage;
worst_mileage = mileage;
}
else{
if(mileage>best_mileage) {
best_mileage=mileage;
}
if (mileage<worst_mileage) {
    worst_mileage=mileage;
}
}
}

// *Prints the current logged record in a formatted table*//
void print_current_record(void) {
printf("----------------------------------------------------------------------------------\n");
printf(" %-4s | %-10s | %-9s | %-9s | %-10s | %-10s | %-10s|\n","NO","ODOMETER","LITRES","PRICE","DISTANCE","COST","MILEAGE");
printf("-----------------------------------------------------------------------------------\n");
printf(" %-4d | %-10d | %-9.2f | %-9.2f | %-10d | %-10.2f | %-10.2f|\n",fill_up,current_odometer,litres, price,distance,cost,mileage);
printf("-----------------------------------------------------------------------------------\n");
}

// *Prints the overall report with total sums*//
void print_final_report(void) {
    //*Guard clause: Prevent division by zero if no records exist*//
if (total_fill_ups == 0) {
printf("\n [!] No records found. Please log a fill-up first (Choice 1).\n");
return;
}
printf("\n==============================================================\n");
printf("                    OVERALL MILEAGE REPORT                    \n");
printf("================================================================\n");

if(total_distance > 0){
printf(" Overall Cost per km\t:\t%.2f Taka\n",total_cost / total_distance);
}else{
printf(" Overall Cost per km\t:\tN/A\n");
}
printf(" Total Fill-ups\t\t:\t%d\n",total_fill_ups);
printf(" Total Distance\t\t:\t%d km\n",total_distance);
printf(" Total Fuel Used\t:\t%.2f Litres\n",total_litres);
printf(" Total Cost\t\t:\t%.2f Taka\n",total_cost);
 // *Calculate average mileage (Total mileage / Total records)*//
printf(" Average Mileage\t:\t%.2f km/l\n", total_mileage / total_fill_ups);
printf("==============================================================\n");
}

// *Prints the best and worst mileage recorded so far*//
void print_best_worst(void){
if(total_fill_ups==0){
printf("\nNo records found.\n");
return;
}
printf("\n==============================================================\n");
printf("                  BEST AND WORST MILEAGE                      \n");
printf("================================================================\n");
printf(" Best Mileage(So Far)\t:%.2f km/l\n", best_mileage);
printf(" Worst Mileage(So Far)\t:%.2f km/l\n", worst_mileage);
printf("================================================================\n");
}

// *Prints the overall cost per kilometre*//
void print_cost_per_km(void) {
     //*Guard clause: Prevent division by zero*//
if(total_fill_ups==0||total_distance==0) {
printf("\nNot enough data to calculate cost per kilometre.\n");
return;
}
printf("\n==============================================================\n");
printf("                   COST PER KILOMETRE REPORT                  \n");
printf("=================================================================\n");
printf(" Total Cost Spent\t:%.2f Taka\n",total_cost);
printf(" Total Distance\t\t:%d km\n",total_distance);
printf(" Average Cost per km\t:%.2f Taka/km\n",total_cost/total_distance);
printf("=================================================================\n");
}
int main(void) {
int choice;
display_banner();  //*Display the banner*//
// Menu Loop (do-while): Menu repeats until the user enters 0//
do{
 display_menu();
 printf("Enter your choice:");
 scanf("%d",&choice);

 // *Switch-Case: Dispatches tasks based on user choice*//
 switch(choice){
 case 1:read_record();  // *Take input*//
        calculate_current();    //*Do math*//
        update_totals();    // *Update running totals*//
        print_current_record(); //* Print the table*//
        break;
 case 2:print_final_report();   //*Show overall report*//
        break;
 case 3:print_best_worst(); // *Show best/worst*//
        break;
 case 4:print_cost_per_km();    //*Show cost per km*//
        break;
 case 0:printf("\nExiting system.Goodbye.\n");
        break;
  default:printf("Invalid choice.\n") ;
 }
}
while(choice!=0);
return 0;
}

