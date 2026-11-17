            MENU


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

// *Prints the current logged record in a formatted table*//
void print_current_record(void) {
printf("----------------------------------------------------------------------------------\n");
printf(" %-4s | %-10s | %-9s | %-9s | %-10s | %-10s | %-10s|\n","NO","ODOMETER","LITRES","PRICE","DISTANCE","COST","MILEAGE");
printf("-----------------------------------------------------------------------------------\n");
printf(" %-4d | %-10d | %-9.2f | %-9.2f | %-10d | %-10.2f | %-10.2f|\n",fill_up,current_odometer,litres, price,distance,cost,mileage);
printf("-----------------------------------------------------------------------------------\n");
}
