#include <gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

    //GLOBAL DECLARATION
    
    //"MAIN_WINDOW" POINTERS (VARIABLES) DECLARATION
    GtkBuilder *builder;
    GtkWidget *main_window;


    GtkWidget *dialog;
    
    //"SIGNUP_PAGE" INFOR POINTERS (VARIABLES) DECLARATION
    //LABEL
    GtkLabel    *signup_label,
                *signup_firstname_label, 
                *signup_lastname_label,
                *signup_username_label,
                *signup_gender_label,
                *signup_date_of_birth_label,
                *signup_phone_number_label,
                *signup_password_label,
                *signup_confirm_password_label;
    //ENTRY
    GtkEntry    *signup_firstname_entry,
                *signup_lastname_entry,
                *signup_username_entry,
                *signup_gender_entry,
                *signup_date_of_birth_entry,
                *signup_phone_number_entry,
                *signup_password_entry,
                *signup_confirm_password_entry;

    
//"LOGIN_PAGE" INFOR POINTERS (VARIABLES) DECLARATION
    //LABEL
    GtkLabel    *login_label,
                *login_username_label,
                *login_password_label;
    
    //ENTRY
    GtkEntry    *login_username_entry,
                *login_password_entry;

    GtkButton   *login_confirm_button,
                *login_back_button;


//"EDIT PAGE CONFIRM" INFOR POINTERS (VARIABLES) DECLARATION

    GtkLabel    * edit_profile_confirm_label,
                * edit_profile_confirm_username_label,
                * edit_profile_confirm_password_label;
    
    GtkEntry    * edit_profile_confirm_username_entry,
                * edit_profile_confirm_password_entry; 

    GtkButton   * edit_profile_confirm_finish_button,
                * edit_profile_confirm_back_button;


//"EDIT PAGE" INFOR POINTERS (VARIABLES) DECLARATION

    GtkLabel* edit_profile_label;
    
    GtkLabel* edit_profile_firstname_label,
            * edit_profile_lastname_label, 
            * edit_profile_username_label,
            * edit_profile_gender_label,
            * edit_profile_date_of_birth_label,
            * edit_profile_phone_number_label,
            * edit_profile_password_label,
            * edit_profile_confirmpassword_label;
    
    GtkEntry* edit_profile_firstname_entry,
            * edit_profile_lastname_entry,
            * edit_profile_username_entry,
            * edit_profile_date_of_birth_entry,
            * edit_profile_phone_number_entry,
            * edit_profile_password_entry,
            * edit_profile_confirmpassword_entry;


    GtkWidget       *ComboBoxText_2,
                    *gender_entry_2;

    GtkButton *edit_profile_confirm_button,
              *edit_profile_back_button;



// BACK BUTTON FUNCTION OF SIGNUP AND LOGIN PAGE INFOR

//"SignUp" page "back button" return to main window 

void on_signup_back_button_clicked (GtkButton *signup_back_button, gpointer user_data){         
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page0");  
    g_print("Button clicked! 3\n");
}

//"Login" page "back button" return to main window 

void on_login_back_button_clicked (GtkButton *login_back_button, gpointer user_data){         
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page0");  
    g_print("Button clicked! 4\n");
}

//"Edit profile" page "back button" return to main window 
void on_edit_profile_confirm_back_button_clicked (GtkButton *edit_profile_confirm_back_button, gpointer user_data){         
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page0");  
    g_print("Button clicked! 5\n");
}

//"Edit profile confirm" page "back button" return to main window 
void on_edit_profile_back_button_clicked (GtkButton *edit_profile_back_button, gpointer user_data){         
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page3");  
    g_print("Button clicked! 6\n");
}
//**********************************************************************************************************************************************************************************************************

// "LOGIN" AND "SIGNUP" BUTTON IN "MAIN_WINDOW" FUNCTION

//"login_button_main_window" function opens from "main window" to "login page"

void on_login_button_main_window_clicked (GtkButton *login_button_main_window, gpointer user_data){         
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page1");  //page1 is the name set in the "Packing" 
    g_print("Button clicked!\n");
}

//"sign_up_button_main_window" function opens from "main window" to "signup page" 

void on_sign_up_button_main_window_clicked (GtkButton *sign_up_button_main_window, gpointer user_data){     
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page2"); 
    g_print("Button clicked 2!\n");
}



void on_edit_profile_confirm_button_main_window_clicked (GtkButton *edit_profile_confirm_button_main_window, gpointer user_data){     
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "page3"); 
    g_print("Button clicked 2!\n");
}

void on_delete_account_button_main_window_clicked (GtkButton *delete_account_button_main_window, gpointer user_data){}  
//***********************************************************************************************************************************************************************************************************

// CONDITION OF EACH ENTRY IN "LOGIN" MAIN_FUNCTION


    const char *login_username;
    const char *login_password;


void on_login_confirm_button_clicked(GtkButton *login_confirm_button, gpointer data)
{
    login_username             =           gtk_entry_get_text(GTK_ENTRY(login_username_entry));         //Username
    login_password             =           gtk_entry_get_text(GTK_ENTRY(login_password_entry));         //Password

    FILE *file = fopen("user_data.txt", "r");
    
    char file_signup_firstname[100], file_signup_lastname[100], file_signup_username[100], file_signup_phone_number[20], file_signup_password[100], file_signup_confirm_password[100];
    gboolean match_found = FALSE;

    while (fscanf(file, "%s %s %s %s %s %s", file_signup_firstname, file_signup_lastname, file_signup_username, file_signup_phone_number, file_signup_password, file_signup_confirm_password) == 6) { 
        if (strcmp(login_username, file_signup_username) == 0 && strcmp(login_password, file_signup_password) == 0)
        {
            match_found = TRUE;
            break;
        }
    fclose(file);
    }


    if (match_found) {
        dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "Login successful!");
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);    
    
    }else{
        dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_ERROR,
                                               GTK_BUTTONS_OK,
                                               "Login failed. Please enter valid input.");
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    }

}


// CONDITION OF EACH ENTRY IN "SIGN UP" MAIN_FUNCTION

    const char *signup_firstname;        
    const char *signup_lastname;                              
    const char *signup_username;                           
    const char *signup_phone_number;                           
    const char *signup_password;                               
    const char *signup_confirm_password; 

void on_signup_confirm_button_clicked(GtkButton *signup_confirm_button, gpointer data)
{
    
    signup_firstname            =           gtk_entry_get_text(GTK_ENTRY(signup_firstname_entry));          //First Name
    signup_lastname             =           gtk_entry_get_text(GTK_ENTRY(signup_lastname_entry));           //Last Name
    signup_username             =           gtk_entry_get_text(GTK_ENTRY(signup_username_entry));           //Username
    signup_phone_number         =           gtk_entry_get_text(GTK_ENTRY(signup_phone_number_entry));       //Phone Number
    signup_password             =           gtk_entry_get_text(GTK_ENTRY(signup_password_entry));           //Password
    signup_confirm_password     =           gtk_entry_get_text(GTK_ENTRY(signup_confirm_password_entry));   //Confirm password

//PHONE NUMBER CONDITION 
    gboolean is_valid = TRUE;
    for (guint i = 0; i < strlen(signup_phone_number); i++) {
        if (!g_ascii_isdigit(signup_phone_number[i])) {
        is_valid = FALSE;
        break;
    }
}

    if (strlen(signup_firstname)        <= 10      &&       strlen(signup_firstname) != 0 
    &&  strlen(signup_lastname)         <= 10      &&       strlen(signup_lastname)  != 0 
    &&  strlen(signup_username)         >= 8       &&       strlen(signup_username)  != 0 
    &&  strlen(signup_phone_number)     == 10      &&       is_valid
    &&  strlen(signup_password)         >= 8       &&       strlen(signup_password)  != 0
    &&  strcmp(signup_password, signup_confirm_password) == 0)//
    { 
    dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "Sign-up successful!");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    FILE *file = fopen("user_data.txt", "a");

    
    fprintf(file, "%s %s %s %s %s %s", signup_firstname, signup_lastname, signup_username, signup_phone_number, signup_password, signup_confirm_password);

    fclose(file);

    }else{ 
    /* Show a failure dialog */
    dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_ERROR,
                                               GTK_BUTTONS_OK,
                                               "Sign-up failed. Please enter valid input.");
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

  }
}


// CONDITION OF EACH ENTRY IN "EDIT PROFILE CONFIRM" MAIN_FUNCTION

void on_edit_profile_confirm_finish_button_clicked(GtkButton *edit_profile_confirm_finish_button, gpointer data){
    const char *edit_profile_confirm_username;
    const char *edit_profile_confirm_password;

    edit_profile_confirm_username             =           gtk_entry_get_text(GTK_ENTRY(edit_profile_confirm_username_entry));         //Username
    edit_profile_confirm_password             =           gtk_entry_get_text(GTK_ENTRY(edit_profile_confirm_password_entry));         //Password

    FILE *file = fopen("user_data.txt", "r");
    
    char file_edit_profile_confirm_firstname[100], file_edit_profile_confirm_lastname[100], file_edit_profile_confirm_username[100], file_edit_profile_confirm_phone_number[20], file_edit_profile_confirm_Password[100], file_edit_profile_confirm_Confirm_password[100];
    gboolean match_found = FALSE;

    while (fscanf(file, "%s %s %s %s %s %s", file_edit_profile_confirm_firstname, file_edit_profile_confirm_lastname, file_edit_profile_confirm_username, file_edit_profile_confirm_phone_number, file_edit_profile_confirm_Password, file_edit_profile_confirm_Confirm_password) == 6) { 
        if (strcmp(edit_profile_confirm_username, file_edit_profile_confirm_username) == 0 && strcmp(edit_profile_confirm_password, file_edit_profile_confirm_Password) == 0)
        {
            match_found = TRUE;
            break;
        }
    fclose(file);
    }


    if (match_found) {
        dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "Confirm your Account successful!");
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);    
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page4");     
    }else{
        dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_ERROR,
                                               GTK_BUTTONS_OK,
                                               "Confirm failed. Please enter valid input.");
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    }

}


// CONDITION OF EACH ENTRY IN "EDIT PROFILE" ENTRY (THE NEXT PAGE OF "EDIT PROFILE CONFIRM")

    const char *edit_profile_firstname;        
    const char *edit_profile_lastname;                              
    const char *edit_profile_username;                           
    const char *edit_profile_phone_number;                           
    const char *edit_profile_password;                               
    const char *edit_profile_confirmpassword; 

void on_edit_profile_confirm_button_clicked(GtkButton *edit_profile_confirm_button, gpointer data){

    edit_profile_firstname            =           gtk_entry_get_text(GTK_ENTRY(edit_profile_firstname_entry));          //First Name
    edit_profile_lastname             =           gtk_entry_get_text(GTK_ENTRY(edit_profile_lastname_entry));           //Last Name
    edit_profile_username             =           gtk_entry_get_text(GTK_ENTRY(edit_profile_username_entry));           //Username
    edit_profile_phone_number         =           gtk_entry_get_text(GTK_ENTRY(edit_profile_phone_number_entry));       //Phone Number
    edit_profile_password             =           gtk_entry_get_text(GTK_ENTRY(edit_profile_password_entry));           //Password
    edit_profile_confirmpassword     =           gtk_entry_get_text(GTK_ENTRY(edit_profile_confirmpassword_entry));   //Confirm password

//PHONE NUMBER CONDITION 
    gboolean is_valid = TRUE;
    for (guint i = 0; i < strlen(edit_profile_phone_number); i++) {
        if (!g_ascii_isdigit(edit_profile_phone_number[i])) {
        is_valid = FALSE;
        break;
    }
}

    if (strlen(edit_profile_firstname)        <= 10      &&       strlen(edit_profile_firstname) != 0 
    &&  strlen(edit_profile_lastname)         <= 10      &&       strlen(edit_profile_lastname)  != 0 
    &&  strlen(edit_profile_username)         >= 8       &&       strlen(edit_profile_username)  != 0 
    &&  strlen(edit_profile_phone_number)     == 10      &&       is_valid
    &&  strlen(edit_profile_password)         >= 8       &&       strlen(edit_profile_password)  != 0
    &&  strcmp(edit_profile_password, edit_profile_confirmpassword) == 0)
    { 
    dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "Edit profile successful!");

    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    GtkStack *stack = GTK_STACK(data);
    gtk_stack_set_visible_child_name(stack, "page0");   


    FILE *file = fopen("user_data.txt", "w");

    
    fprintf(file, "%s %s %s %s %s %s", edit_profile_firstname, edit_profile_lastname, edit_profile_username, edit_profile_phone_number, edit_profile_password, edit_profile_confirmpassword);

    fclose(file);


    }else{ 
    /* Show a failure dialog */
    dialog = gtk_message_dialog_new(NULL,
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_ERROR,
                                               GTK_BUTTONS_OK,
                                               "Edit failed. Please enter valid input.");
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

  }
}



int main(int argc, char *argv[])
{
    //DECLARATION OF MAIN WINDOW
    
    GtkWidget       *main_window_label;
    
    GtkWidget       *login_button_main_window, 
                    *sign_up_button_main_window,
                    *edit_profile_confirm_button_main_window,
                    *delete_account_button_main_window;

    GtkStack        *stack;
    
    gtk_init(&argc, &argv);

    //MAIN WINDOW 
    builder =                   gtk_builder_new();                                                                    //Create builder
    gtk_builder_add_from_file(builder,"project.glade", NULL);                                      //Connect to "project.glade" file to get information and 


    main_window =                   GTK_WIDGET  (gtk_builder_get_object(builder, "Main_Window"));                       //Create main_window(in the main_window will have Login and SignUp button)
    stack =                         GTK_STACK   (gtk_builder_get_object(builder, "stack"));                                    //Create stack 
    main_window_label =             GTK_WIDGET  (gtk_builder_get_object(builder, "Main_Window_Label"));


    login_button_main_window =              GTK_WIDGET  (gtk_builder_get_object(builder, "login_button_main_window"));
    sign_up_button_main_window =            GTK_WIDGET  (gtk_builder_get_object(builder, "sign_up_button_main_window"));
    edit_profile_confirm_button_main_window =       GTK_WIDGET  (gtk_builder_get_object(builder, "edit_profile_confirm_button_main_window"));
    delete_account_button_main_window =     GTK_WIDGET  (gtk_builder_get_object(builder, "delete_account_button_main_window"));

    g_signal_connect(login_button_main_window,              "clicked",      G_CALLBACK(on_login_button_main_window_clicked),                stack);
    g_signal_connect(sign_up_button_main_window,            "clicked",      G_CALLBACK(on_sign_up_button_main_window_clicked),              stack);    
    g_signal_connect(edit_profile_confirm_button_main_window,       "clicked",      G_CALLBACK(on_edit_profile_confirm_button_main_window_clicked),         stack); 
    g_signal_connect(delete_account_button_main_window,     "clicked",      G_CALLBACK(on_delete_account_button_main_window_clicked),       stack); 

//*********************************************************************************************************************************************************************************************************
    
    //"LOGIN" PAGE INFORMATION
    
    GtkGrid *grid;      //GRID IN "LOGIN" PAGE

    grid = GTK_GRID(gtk_builder_get_object(builder, "grid"));
    

    login_label =                           GTK_LABEL(gtk_builder_get_object(builder, "login_label"));
    login_username_label =                  GTK_LABEL(gtk_builder_get_object(builder, "login_username_label"));
    login_username_entry =                  GTK_ENTRY(gtk_builder_get_object(builder, "login_username_entry"));

    login_password_label =                  GTK_LABEL(gtk_builder_get_object(builder, "login_password_label"));
    login_password_entry =                  GTK_ENTRY(gtk_builder_get_object(builder, "login_password_entry"));

    login_confirm_button =                  GTK_BUTTON(gtk_builder_get_object(builder, "login_confirm_button"));
    login_back_button =                     GTK_BUTTON(gtk_builder_get_object(builder, "login_back_button"));
    
    
    g_signal_connect(login_confirm_button, "clicked", G_CALLBACK(on_login_confirm_button_clicked), NULL);        
    
    g_signal_connect(login_back_button, "clicked", G_CALLBACK(on_login_back_button_clicked), stack);

 
 //********************************************************************************************************************************************************************************************************   
    
    //"SIGN UP" PAGE INFORMATION
    
    GtkGrid *grid2;    //GRID IN "SIGN UP" PAGE

    grid2 = GTK_GRID(gtk_builder_get_object(builder, "grid2"));

    signup_label =                      GTK_LABEL(gtk_builder_get_object(builder, "signup_label"));
    
    signup_firstname_label =            GTK_LABEL(gtk_builder_get_object(builder, "signup_firstname_label"));
    signup_firstname_entry =            GTK_ENTRY(gtk_builder_get_object(builder, "signup_firstname_entry"));

    signup_lastname_label =             GTK_LABEL(gtk_builder_get_object(builder, "signup_lastname_label"));
    signup_lastname_entry =             GTK_ENTRY(gtk_builder_get_object(builder, "signup_lastname_entry"));

    signup_username_label =             GTK_LABEL(gtk_builder_get_object(builder, "signup_username_label"));
    signup_username_entry =             GTK_ENTRY(gtk_builder_get_object(builder, "signup_username_entry"));

    signup_gender_label =               GTK_LABEL(gtk_builder_get_object(builder, "signup_gender_label"));
    //signup_gender_entry = GTK_ENTRY(gtk_builder_get_object(builder, "lastname_entry"));
    GtkWidget *ComboBoxText =           GTK_WIDGET(gtk_builder_get_object(builder, "signup_gender_list"));
    GtkWidget *gender_entry =           GTK_WIDGET(gtk_builder_get_object(builder, "signup_gender_entry"));
    //GtkWidget *signup_gender_entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "signup_gender_entry"));

    signup_date_of_birth_label =        GTK_LABEL(gtk_builder_get_object(builder, "signup_date_of_birth_label"));
    signup_date_of_birth_entry =        GTK_ENTRY(gtk_builder_get_object(builder, "signup_date_of_birth_entry"));

    signup_phone_number_label =         GTK_LABEL(gtk_builder_get_object(builder, "signup_phone_number_label"));
    signup_phone_number_entry =         GTK_ENTRY(gtk_builder_get_object(builder, "signup_phone_number_entry"));

    signup_password_label =             GTK_LABEL(gtk_builder_get_object(builder, "signup_password_label"));
    signup_password_entry =             GTK_ENTRY(gtk_builder_get_object(builder, "signup_password_entry"));

    signup_confirm_password_label =     GTK_LABEL(gtk_builder_get_object(builder, "signup_confirm_password_label"));
    signup_confirm_password_entry =     GTK_ENTRY(gtk_builder_get_object(builder, "signup_confirm_password_entry"));

    GtkButton *signup_confirm_button,
              *signup_back_button;

    
    //
    signup_confirm_button =             GTK_BUTTON(gtk_builder_get_object(builder, "signup_confirm_button"));
    g_signal_connect(signup_confirm_button,     "clicked",      G_CALLBACK(on_signup_confirm_button_clicked),   NULL);
    
    //
    signup_back_button =                GTK_BUTTON(gtk_builder_get_object(builder, "signup_back_button"));
    g_signal_connect(signup_back_button,        "clicked",      G_CALLBACK(on_signup_back_button_clicked),      stack);  

//*********************************************************************************************************************************************************************************************************************    
    
    //"EDIT PROFILE CONFIRM" PAGE INFORMATION

    GtkGrid *grid3;      //GRID IN "EDIT PROFILE CONFIRM" PAGE

    grid3 = GTK_GRID(gtk_builder_get_object(builder, "grid3"));
    

    edit_profile_confirm_label =                         GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_confirm_label"));
    edit_profile_confirm_username_label =                GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_confirm_username_label"));
    edit_profile_confirm_username_entry =                GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_confirm_username_entry"));

    edit_profile_confirm_password_label =                GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_confirm_password_label"));
    edit_profile_confirm_password_entry =                GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_confirm_password_entry"));

    
    //BUTTON
    edit_profile_confirm_finish_button =          GTK_BUTTON(gtk_builder_get_object(builder, "edit_profile_confirm_finish_button"));
    edit_profile_confirm_back_button =                   GTK_BUTTON(gtk_builder_get_object(builder, "edit_profile_confirm_back_button"));
    
    
    g_signal_connect(edit_profile_confirm_finish_button, "clicked", G_CALLBACK(on_edit_profile_confirm_finish_button_clicked), stack);        
    
    g_signal_connect(edit_profile_confirm_back_button, "clicked", G_CALLBACK(on_edit_profile_confirm_back_button_clicked), stack);

//***************************************************************************************************************************************************************************************************************
    
    //"EDIT PROFILE" PAGE INFORMATION
    
    GtkGrid *grid4;    //GRID IN "EDIT PROFILE" PAGE

    grid4 = GTK_GRID(gtk_builder_get_object(builder, "grid4"));

    edit_profile_label =                      GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_label"));
    
    edit_profile_firstname_label =            GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_firstname_label"));
    edit_profile_firstname_entry =            GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_firstname_entry"));

    edit_profile_lastname_label =             GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_lastname_label"));
    edit_profile_lastname_entry =             GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_lastname_entry"));

    edit_profile_username_label =             GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_username_label"));
    edit_profile_username_entry =             GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_username_entry"));

    edit_profile_gender_label =               GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_gender_label"));
    //signup_gender_entry = GTK_ENTRY(gtk_builder_get_object(builder, "lastname_entry"));
    GtkWidget *ComboBoxText_2 =           GTK_WIDGET(gtk_builder_get_object(builder, "edit_profile_gender_list"));
    GtkWidget *gender_entry_2 =           GTK_WIDGET(gtk_builder_get_object(builder, "edit_profile_gender_entry"));
    //GtkWidget *signup_gender_entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "signup_gender_entry"));

    edit_profile_date_of_birth_label =        GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_date_of_birth_label"));
    edit_profile_date_of_birth_entry =        GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_date_of_birth_entry"));

    edit_profile_phone_number_label =         GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_phone_number_label"));
    edit_profile_phone_number_entry =         GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_phone_number_entry"));

    edit_profile_password_label =             GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_password_label"));
    edit_profile_password_entry =             GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_password_entry"));

    edit_profile_confirmpassword_label =     GTK_LABEL(gtk_builder_get_object(builder, "edit_profile_confirmpassword_label"));
    edit_profile_confirmpassword_entry =     GTK_ENTRY(gtk_builder_get_object(builder, "edit_profile_confirmpassword_entry"));

    

    //BUTTON
    edit_profile_confirm_button =             GTK_BUTTON(gtk_builder_get_object(builder, "edit_profile_confirm_button"));
    g_signal_connect(edit_profile_confirm_button,     "clicked",      G_CALLBACK(on_edit_profile_confirm_button_clicked),   stack);
    
    edit_profile_back_button =                GTK_BUTTON(gtk_builder_get_object(builder, "edit_profile_back_button"));
    g_signal_connect(edit_profile_back_button,        "clicked",      G_CALLBACK(on_edit_profile_back_button_clicked),      stack);  
    
    //gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);

    GdkRGBA color;

    color.red = 0.565;
    color.green = 0.933;
    color.blue = 0.565;
    color.alpha = 1.0;
    gtk_widget_override_background_color(main_window, GTK_STATE_FLAG_NORMAL, &color);

    gtk_widget_show_all(GTK_WIDGET(grid));
    gtk_widget_show_all(GTK_WIDGET(grid2));
    gtk_widget_show_all(GTK_WIDGET(grid3));
    gtk_widget_show_all(GTK_WIDGET(grid4));
    gtk_widget_show_all(GTK_WIDGET(main_window));
    
    gtk_main();



    return 0;
}



