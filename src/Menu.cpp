/*
 * Menu.cpp
 *
 *  Created on: May 22, 2016
 *      Author: raydelto/angel
 */

#include "Menu.h"
#include <iostream>
using namespace std;

@@ -14,14 +14,34 @@ Menu::Menu()
 
 }
 
-void Menu::clearScreen()
+
+/*Contact struct holds information for one entry.*/
+/*Contacts with no first name will be recognised as 'deleted'*/
+struct Contact
 {
-	#ifdef _WIN32
-	system("cls");
-	#else
-	system("clear");
-	#endif
-}
+    char first[20]; /*First Name*/
+    char last[30]; /*Last Name*/
+    char areacode[6]; /*Area Code*/
+    char number[10]; /*Telephone Number*/
+    char email[60]; /*E-Mail*/
+    char webaddr[60]; /*Web address of a website -you never know-*/
+    char address[60]; /*Home Address*/
+};
+
+class PhoneBook
+{
+    Contact contact;
+  public:
+    bool CreateMe(){if(contact.first[0]=='\\') return true; else return false;};
+    void Edit();
+    void Delete(){contact.first[0]='\\';};
+    void Print(bool showall);
+    //void PhoneBook::ShowName(){cout << contact.last << " " << contact.first;};
+    //void Save( FILETO );
+    //void Load( FILEFROM );
+    bool SearchContact(char SearchThis[60]);
+};
+
 
 void Menu::pause()
 {
@@ -31,85 +51,169 @@ void Menu::pause()
 	system("read -n1 -r -p \"Press any key to continue...\" key");
 	#endif
 }
+/*showing the user an interface to the user*/
+void PhoneBook::Edit()
+{
+    cout << endl << "FirstName: ";
+    cin >> contact.first;
 
+    cout << endl << "LastName: ";
+    cin >> contact.last;
 
-bool Menu::validate(int option)
-{
-	if(option >= 1 && option <= 5)
-	{
-		return true;
-	}else
-	{
-		cout << "Please pick an option between 1 and 5"<< endl;
-		pause();
-		return false;
-	}
-}
+    cout << endl << "Area Code: ";
+    cin >> contact.areacode;
 
-void Menu::routeAction(int option)
-{
-	switch(option)
-	{
-	case 1:
-		listContacts();
-		break;
-	case 2:
-		addContacts();
-		break;
-	case 3:
-		removeContacts();
-		break;
-	case 4:
-		modifyContacts();
-		break;
-
-	case 5:
-		cout << "Thanks for using our software, good bye!" << endl;
-	}
-	pause();
-}
+    cout << endl << "Number: ";
+    cin >> contact.number;
 
-void Menu::listContacts()
-{
-	//TODO: Implement this
-	cout << "Implement  Menu::listContacts" << endl;
-}
+    cout << endl << "e-mail: ";
+    cin >> contact.email;
 
-void Menu::addContacts()
-{
-	//TODO: Implement this
-	cout << "Implement  Menu::addContacts" << endl;
+    cout << endl << "WebAddress: ";
+    cin >> contact.webaddr;
+
+    cout << endl << "HomeAddress: ";
+    cin >> contact.address;
+    cout << "OK." << endl;
 }
 
-void Menu::removeContacts()
+void PhoneBook::Print(bool showall)
 {
-	//TODO: Implement this
-	cout << "Implement  Menu::removeContacts" << endl;
+    /*showing the user an interface to the user to choose an opcion*/
+    cout << endl << "FirstName: " << contact.first
+        << endl << "LastName: " << contact.last;
+    if(showall){
+        cout << endl << "Area Code: " << contact.areacode
+            << endl << "Number: " << contact.number
+            << endl << "e-mail: " << contact.email
+            << endl << "WebAddress: " << contact.webaddr
+            << endl << "HomeAddress: " << contact.address
+            << endl << "---" << endl <<  "OK." << endl;
+    }
 }
 
-void Menu::modifyContacts()
+bool PhoneBook::SearchContact(char searchThis[60])
 {
-	//TODO: Implement this
-	cout << "Implement  Menu::modifyContacts" << endl;
+    if(!strcmp(contact.first, searchThis)){ return true; }
+       else if(!strcmp(contact.last, searchThis)){ return true; }
+       /* --SEARCHING A PERSON WITH ONLY HIS AREA CODE*/
+       else if(!strcmp(contact.areacode, searchThis)){ return true; }
+       else if(!strcmp(contact.number, searchThis)){ return true; }
+       else if(!strcmp(contact.email, searchThis)){ return true; }
+       else if(!strcmp(contact.webaddr, searchThis)){ return true; }
+       else if(!strcmp(contact.address, searchThis)){ return true; }
+    else {return false;};
 }
 
-void Menu::show()
+//void SaveAll();
+//void LoadAll();
+
+/*---------------------------------------*/
+/*  CLEAR THE SCREEN AND PUT THE HEADER  */
+inline void clearscreen()
 {
-	int option;
-	do
-	{
-		clearScreen();
-		cout << "ITLA Phonebook" << endl;
-		cout << "1- List contacts" << endl;
-		cout << "2- Add contacts" << endl;
-		cout << "3- Remove contact" << endl;
-		cout << "4- Modify contact" << endl;
-		cout << "5- Exit" << endl;
-		cout << "Select an option => ";
-		cin >> option;
-		if(validate(option))
-		{
-			routeAction(option);
-		}
-	}while(option !=5);
+    system("CLS"); /* Clear the screen */
+    cout << "SIMPLE PHONE_BOOK by thetrojan01" << endl
+        << "--------------------------------" << endl << endl;
 }
+int main()
+{
+    /*Definitions and prepairations*/
+    PhoneBook book[MAX_CONTACTS];
+    char Mnuoption='0';
+    int i;
+    char buff[60];
+    bool found;
+
+    for(int j=0; j<MAX_CONTACTS; j++)
+        book[j].Delete();
+
+    clearscreen();
+    while(Mnuoption != '6')
+       {
+               found=false;
+               i=0;
+               /*showing the user an interface to the user to choose an opcion*/
+               cout << "1. Create New Contact" << endl;
+               cout << "2. Edit Contact's data" << endl;
+               cout << "3. Delete a Contact" << endl;
+               cout << "4. Search a Contact" << endl;
+               cout << "5. Save All Data" << endl;
+               cout << "6. Terminate program" << endl;
+
+           cout << endl << "Selection: ";
+           cin >> Mnuoption;
+
+           switch(Mnuoption)  /*making cases*/
+           {
+               case '1':
+
+                   do
+                   {
+                       if(book[i].CreateMe()){
+                            book[i].Edit();
+                            found = true;
+                       }
+                       i++;
+                   }while(i < MAX_CONTACTS && !found);
+                   break;
+
+               case '2':
+                   cout << "Please, give me a name or sth..." << endl;
+                   cin >> buff;
+                   if(book[i].SearchContact(buff) && !book[i].CreateMe())
+                   {
+                       cout << endl << "EDITING: ";
+                       book[i].Print(false);
+                       book[i].Edit();
+                   }
+                   else
+                   {
+                       i++;
+                   }
+                   break;
+
+               case '3':
+                   cout << "Please, give me a name or sth..." << endl;
+                   cin >> buff;
+                   if(book[i].SearchContact(buff) && !book[i].CreateMe())
+                   {
+                       cout << endl << "DELETING: ";
+                       book[i].Print(true);
+                       cout << endl << "Are you sure? (y/n)";
+                       cin >> buff[0];
+                       if(buff[0]=='y') book[i].Delete();
+                   }
+                   else
+                   {
+                       i++;
+                   }
+                   break;
+
+               case '4':
+                   cout << endl << "Search: " << endl;
+                   cin >> buff;
+
+                   if(book[i].SearchContact(buff) && !book[i].CreateMe())
+                   {
+                       book[i].Print(true);
+                       cout << endl;
+                   }
+                   else
+                   {
+                       i++;
+                   }
+                   break;
+                   cout << endl << "Type a number to continue ";
+                   cin >> i;
+
+               case '5':
+                   /*SAVE Data*/
+                   break;
+           }
+       }
+       cout << endl << endl << "END. " << endl; /*here we end the program*/
+       system("PAUSE");
+       return 0;
+   }