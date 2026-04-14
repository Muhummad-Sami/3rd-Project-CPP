#include <iostream>
#include <string>
#include <windows.h> // for Sleep function
#include <conio.h>   // for getch function
#include <limits>    // for clearing input buffers
#include <cstdlib>   // for exit function
#include <fstream>   // for file handling
#include <iomanip>   // format your console output neatly

using namespace std;

// Function to display the main menu
void displayMainMenu() {
    system("cls");
    cout << endl << "\t\t\t************************************************************************************" << endl << endl;
    cout << "\t\t\t--------------------------- HOSPITAL MANAGEMENT SYSTEM -----------------------------" << endl << endl;
    cout << "\t\t\t************************************************************************************" << endl << endl;
    cout << "\t\t\t------------------------------- Welcome To Main Menu -------------------------------" << endl << endl;
    cout << "\t\t\t************************************************************************************" << endl << endl;

    cout << "  1. Manage Doctors" << endl;
    cout << "  2. Manage Patients" << endl;
    cout << "  3. Manage Appointments" << endl;
    cout << "  4. Manage Medical Reports" << endl;
    cout << "  5. Manage Departments" << endl;
    cout << "  0. Exit" << endl << endl;
    cout << " Enter your option: ";
}

// Function to display project name header
void ProjectName() {
    system("cls");
    cout << endl << "\t\t\t************************************************************************************" << endl << endl;
    cout << "\t\t\t--------------------------- HOSPITAL MANAGEMENT SYSTEM -----------------------------" << endl << endl;
    cout << "\t\t\t************************************************************************************" << endl << endl;
}

// Doctor structure
struct Doctor {
    int id;
    string name;
    string specialty;
    Doctor* prev;
    Doctor* next;

    Doctor(int i, string n, string s) {
        id = i;
        name = n;
        specialty = s;
        prev = next = nullptr;
    }
};

// Doctor Management using Doubly Linked list

class DoctorManager {
private:
    Doctor* head;
    Doctor* tail;

public:
    DoctorManager() {
        head = tail = nullptr;
    }

// Add doctor at the end
    void addDoctor() {
    	int id;
        string name, specialty;
    	Doctor* newDoc = new Doctor(id, name, specialty);

        cout << " Enter Doctor ID: ";
        cin >> newDoc->id;
        cin.ignore();
        cout << " Enter Name: ";
        getline(cin, newDoc->name);
        cout << " Enter Specialty: ";
        getline(cin, newDoc->specialty);

        if (!head) {
            head = tail = newDoc;
        } else {
            tail->next = newDoc;
            newDoc->prev = tail;
            tail = newDoc;
        }

        cout << "\n Doctor added In the List successfully";
        for (int i = 0; i < 4; i++) {
            cout << ".";
            Sleep(500);
        }
        cout << endl;
        ofstream bill("sample.txt", ios::app); 
	    if (bill.is_open()) {
	        bill << "==================================================" << endl;
	        bill << "                  Doctor Records                  " << endl;
	        bill << "==================================================" << endl;
	        bill << endl;
	
	        bill << "Doctor ID: " << newDoc->id << endl;
	        bill << "Doctor Name: " << newDoc->name << endl;
	        bill << "Doctor Specialty: " << newDoc->specialty << endl;
	        bill << endl;
	
	        bill.close(); 
	    } else 
		{
	        cout << "Error opening file for writing!" << endl;
	    }
    }

// Delete doctor by ID
	void deleteDoctor() 
	{
	    int id;
	    cout << " Enter Doctor ID to delete: ";
	    cin >> id;
	
	    Doctor* temp = head;
	
	    // Search doctor
	    while (temp && temp->id != id) {
	        temp = temp->next;
	    }
	
	    // If not found
	    if (temp == nullptr) {
	        cout << " Doctor not found.\n";
	        return;
	    }
	
	    string docName = temp->name;
	    int docId = temp->id;
	
	    // If deleting head
	    if (temp == head) {
	        head = head->next;
	        if (head != nullptr)
	            head->prev = nullptr;
	    }
	
	    // If deleting tail
	    if (temp == tail) {
	        tail = tail->prev;
	        if (tail != nullptr)
	            tail->next = nullptr;
	    }
	
	    // Update previous node
	    if (temp->prev != nullptr)
	        temp->prev->next = temp->next;
	
	    // Update next node
	    if (temp->next != nullptr)
	        temp->next->prev = temp->prev;
	
	    delete temp;

	    cout << "\n Doctor " << docName << " with ID " << docId << " is Deleting ";	
	    for (int i = 0; i < 4; i++) {
	        cout << ".";
	        Sleep(500);
	    }
	    
	    cout << endl;
	    cout << " Doctor Has Deleted Successfully From the List !!";
	    
	    ofstream bill("sample.txt", ios::app); 
	    if (bill.is_open()) {
	        bill << "==================================================" << endl;
	        bill << "              Deleted Doctor Records              " << endl;
	        bill << "==================================================" << endl;
	        bill << endl;
	
	        bill << "Doctor Deleted ID: " << id << endl;
	        bill << endl;
	        bill.close(); 
	    } 
		else 
		{
	        cout << "Error opening file for writing!" << endl;
	    }
}

// Display all doctors
    void displayDoctors() {
        cout << "\n Doctor List\n\n";
        cout << setw(8) << left << "ID"
             << setw(25) << left << "Name"
             << setw(20) << left << "Specialty" << endl << endl;

        Doctor* temp = head;
        while (temp) {
            cout << setw(8) << left << temp->id
                 << setw(25) << left << temp->name
                 << setw(20) << left << temp->specialty << endl;
            temp = temp->next;
        }
    }
};

// Patient Management using Stack (Linked List)

class Node {
private:
    int Id;
    string Name, Address, Disease, contact;
    Node* next;

    Node() {
        next = nullptr;
    }
    friend class patient;
};

class patient {
private:
    Node* head;

public:
    patient() {
        head = nullptr;
    }

    // Add patient at the head (top of stack)
    void pushPatient() {
        Node* newNode = new Node();

        cout << "\n Enter Patient ID: ";
        cin >> newNode->Id;
        cin.ignore();
        cout << " Enter Name: ";
        getline(cin, newNode->Name);
        cout << " Enter Address: ";
        getline(cin, newNode->Address);
        cout << " Enter Disease: ";
        getline(cin, newNode->Disease);
        cout << " Enter Contact Number: ";
        getline(cin, newNode->contact);

        newNode->next = head;
        head = newNode;

        cout << "\n Patient adding at the Top of Stack ";
        for (int i = 1; i <= 4; i++) {
            cout << ".";
            Sleep(500);
        }
        cout << endl << " Patient Added Successfully !!";

        // File Handling: Append patient info to file
        ofstream bill("sample.txt", ios::app);
        if (bill.is_open()) {
            bill << "==================================================" << endl;
            bill << "                  Patient Records                " << endl;
            bill << "==================================================" << endl;
            bill << "Patient ID: " << newNode->Id << endl;
            bill << "Name: " << newNode->Name << endl;
            bill << "Address: " << newNode->Address << endl;
            bill << "Disease: " << newNode->Disease << endl;
            bill << "Contact: " << newNode->contact << endl;
            bill << endl;
            bill.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }
    }

    // Remove patient from the head (top of stack)
    void popPatient() {
        if (head == nullptr) {
            cout << "\n Stack is empty. No patient to remove.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "\n Removing Patient ID: " << temp->Id << ", Name: " << temp->Name;
        for (int i = 1; i <= 4; i++) {
            cout << ".";
            Sleep(500);
        }
        delete temp;
        cout << "\n Patient record removed From The Stack successfully!\n";

        // File Handling: Log deleted patient
        ofstream bill("sample.txt", ios::app);
        if (bill.is_open()) {
            bill << "==================================================" << endl;
            bill << "                Deleted Patient Record           " << endl;
            bill << "==================================================" << endl;
            bill << "Patient Deleted ID: " << temp->Id << endl;
            bill << endl;
            bill.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }
    }

    // Display stack 
    void displayStack() {
        if (head == nullptr) {
            cout << "\n No patients found.\n";
            return;
        }

        cout << "\n\t\t\t---------------------------- PATIENT LIST (Top to Bottom) ----------------------------\n\n";
        cout << setw(8) << left << "ID"
             << setw(25) << left << "Name"
             << setw(20) << left << "Disease"
             << setw(25) << left << "Address"
             << setw(15) << left << "Contact" << endl << endl;

        Node* temp = head;
        while (temp != nullptr) {
            cout << setw(8) << left << temp->Id
                 << setw(25) << left << temp->Name
                 << setw(20) << left << temp->Disease
                 << setw(25) << left << temp->Address
                 << setw(15) << left << temp->contact << endl;
            temp = temp->next;
        }
    }
};

// Appointment Management using Queue (by array)

	struct AppointmentRecord {
    int patientId;
    int doctorId;
};

class Appointment {
private:
    AppointmentRecord queue[50];
    int front, rear;

public:
    Appointment() {
        front = rear = -1;
    }

    // Add Appointment in a queue using Arrays
    void AppointmentEnqueue(int patientId, int doctorId) {
        if (rear == 49) {
            cout << " Queue Of Appointment is Full\n";
            return;
        } 
		else 
		{
            if (front == -1) {
                front = 0;
            }
            rear++;
            queue[rear].patientId = patientId;
            queue[rear].doctorId = doctorId;

            cout << "\n Appointment booked successfully And Added In The Queue From Last ";
            for (int i = 0; i < 4; i++) { 
                cout << "."; 
                Sleep(300); 
            }
            cout << endl;

            // bill Handling: Log booked appointment
            ofstream bill("sample.txt", ios::app);
            if (bill.is_open()) {
                bill << "==================================================" << endl;
                bill << "                  Appointment Records           " << endl;
                bill << "==================================================" << endl;
                bill << "Patient ID: " << patientId << endl;
                bill << "Doctor ID: " << doctorId << endl;
                bill << endl;
                bill.close();
            } else {
                cout << "Error opening file for writing!" << endl;
            }
        }
    }

    // Remove Appointment from front of queue
    void AppointmentDequeue() {
        if (front == -1 || front > rear) {
            cout << "\n No Appointments to Serve (Queue Empty)\n";
            return;
        }

        cout << "\n Serving Appointment To the Top Of The Queue...\n\n";
        cout << setw(15) << left << " Patient ID: " << queue[front].patientId
             << setw(15) << left << ", Doctor ID: " << queue[front].doctorId << endl;
        front++;
        if (front > rear) front = rear = -1; // reset queue
        
        // bill Handling: Log served appointment
        ofstream bill("sample.txt", ios::app);
        if (bill.is_open()) {
            bill << "==================================================" << endl;
            bill << "               Served Appointment Record         " << endl;
            bill << "==================================================" << endl;
            bill << "Patient Served ID: " << queue[front].patientId << endl;
            bill << "Doctor Served ID: " << queue[front].doctorId << endl;
            bill << endl;
            bill.close();
        }
    }

    // Display
    void displayAppointments() {
        if (front == -1) {
            cout << "\n No appointments found.\n";
            return;
        }

        cout << "\n--- Appointments Queue ---\n\n";
        cout << setw(15) << left << "Patient ID" << setw(15) << left << "Doctor ID" << endl;
        for (int i = front; i <= rear; i++) {
            cout << setw(15) << left << queue[i].patientId
                 << setw(15) << left << queue[i].doctorId << endl;
        }
    }
};

// Medical Reports Management using BST

struct Report {
    int reportId;
    int patientId;
    string diagnosis;
    string prescription;
    Report* left;
    Report* right;

    Report(int r, int p, string d, string pr) {
        reportId = r;
        patientId = p;
        diagnosis = d;
        prescription = pr;
        left = right = nullptr;
    }
};

class MedicalReport {
private:
    Report* root;

    // Insert Node (Recursively)
    Report* insert(Report* node, Report* newNode) {
        if (node == nullptr)
            return newNode;

        if (newNode->reportId < node->reportId)
            node->left = insert(node->left, newNode);
        else
            node->right = insert(node->right, newNode);

        return node;
    }

    // Display In-order
    void inorder(Report* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << "\n Report ID: " << node->reportId;
        cout << "\n Patient ID: " << node->patientId;
        cout << "\n Diagnosis: " << node->diagnosis;
        cout << "\n Prescription: " << node->prescription;
        cout << "\n-----------------------------------------";

        inorder(node->right);
    }

    // Search Report
    Report* search(Report* node, int id) {
        if (!node || node->reportId == id) return node;

        if (id < node->reportId)
            return search(node->left, id);

        return search(node->right, id);
    }

public:
    MedicalReport() {
        root = nullptr;
    }

    // Add Report
    void addReport() {
        int rId, pId;
        string diag, pres;

        cout << "\n Enter Report ID: ";
        cin >> rId;
        cout << " Enter Patient ID: ";
        cin >> pId;
        cin.ignore();
        cout << " Enter Diagnosis: ";
        getline(cin, diag);
        cout << " Enter Prescription: ";
        getline(cin, pres);

        Report* newNode = new Report(rId, pId, diag, pres);
        root = insert(root, newNode);

        cout << "\n Report Added Successfully in The Tree";
        for (int i = 1; i <= 4; i++) {
            cout << ".";
            Sleep(500);
        }
        cout << endl;

        // bill Handling: Save report to bill
        ofstream bill("sample.txt", ios::app);
        if (bill.is_open()) {
            bill << "==================================================" << endl;
            bill << "                 Medical Report                  " << endl;
            bill << "==================================================" << endl;
            bill << "Report ID: " << rId << endl;
            bill << "Patient ID: " << pId << endl;
            bill << "Diagnosis: " << diag << endl;
            bill << "Prescription: " << pres << endl;
            bill << endl;
            bill.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }
    }

    // Search Report by ID
    void findReport() {
        int id;
        cout << "\n Enter Report ID to search: ";
        cin >> id;

        Report* r = search(root, id);

        if (!r) {
            cout << "\n Report Not Found!\n";
            return;
        }
        cout << " Medical Report Searching in the Tree";
        for (int i = 1; i <= 4; i++) {
            cout << ".";
            Sleep(500);
        }
        cout << endl << endl;

        cout << "\n Report Found:";
        cout << "\n Report ID: " << r->reportId;
        cout << "\n Patient ID: " << r->patientId;
        cout << "\n Diagnosis: " << r->diagnosis;
        cout << "\n Prescription: " << r->prescription << endl;
    }

    // Display All Reports
    void displayReports() {
        if (!root) {
            cout << "\n No Reports Found.\n";
            return;
        }

        cout << "\n--------- All Medical Reports ---------\n";
        inorder(root);
        cout << endl;
    }
};

// Department Management using Circular Linked List

struct Department {
    int deptId;
    string deptName;
    Department* next;

    Department(int id, string name) {
        deptId = id;
        deptName = name;
        next = nullptr;
    }
};

class DepartmentManager {
private:
    Department* head;

public:
    DepartmentManager() {
        head = nullptr;
    }

    // Add Department (End Insert)
    void addDepartment() {
        int id;
        string name;

        cout << "\n Enter Department ID: ";
        cin >> id;
        cin.ignore();
        cout << " Enter Department Name: ";
        getline(cin, name);

        Department* newDept = new Department(id, name);

        if (!head) {
            head = newDept;
            newDept->next = head;  
        } 
        else {
            Department* temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newDept;
            newDept->next = head;
        }

        cout << "\n Department Added Successfully In circular Linked List";
        for (int i = 1; i <= 4; i++) {
            cout << ".";
            Sleep(500);
        }
        cout << endl;

        // bill Handling: log department
        ofstream bill("sample.txt", ios::app);
        if (bill.is_open()) {
            bill << "==================================================" << endl;
            bill << "                 Department Record                " << endl;
            bill << "==================================================" << endl;
            bill << "Department ID: " << id << endl;
            bill << "Department Name: " << name << endl << endl;
            bill.close();
        } else {
            cout << "Error opening file for writing!" << endl;
        }
    }

    // Delete Department
    void deleteDepartment() {
        if (!head) {
            cout << "\n No Departments Found.\n";
            return;
        }

        int id;
        cout << "\n Enter Department ID to delete: ";
        cin >> id;

        Department *curr = head;
        Department *prev = head;

        // Case 1: Deleting head node
        if (head->deptId == id) {
            cout << "\n Deleting Department:\n";
            cout << " ID: " << curr->deptId << endl;
            cout << " Name: " << curr->deptName << endl;

            // bill Handling: log deletion
            ofstream bill("sample.txt", ios::app);
            if (bill.is_open()) {
                bill << "==================================================" << endl;
                bill << "                Deleted Department Record         " << endl;
                bill << "==================================================" << endl;
                bill << "Deleted Department ID: " << curr->deptId << endl << endl;
                bill << "Deleted Department Name: " << curr->deptName << endl << endl;
                bill.close();
            }

            if (head->next == head) {
                delete head;
                head = nullptr;
                cout << "\n Department Deleted Successfully";
                for (int i = 1; i <= 4; i++) 
				{ cout << "."; 
				  Sleep(500); }
                cout << endl;
                return;
            }

            while (prev->next != head)
                prev = prev->next;

            head = head->next;
            prev->next = head;

            delete curr;

            cout << "\n Department Deleted Successfully";
            for (int i = 1; i <= 4; i++) 
			{ cout << "."; Sleep(500); }
            cout << endl;
            return;
        }

        // Case 2: Deleting non-head node
        prev = head;
        curr = head->next;

        while (curr != head && curr->deptId != id) {
            prev = curr;
            curr = curr->next;
        }

        if (curr->deptId != id) {
            cout << "\n Department Not Found!\n";
            return;
        }

        cout << "\n Deleting Department:\n";
        cout << " ID: " << curr->deptId << endl;
        cout << " Name: " << curr->deptName << endl;

        // bill Handling: log deletion
        ofstream bill("sample.txt", ios::app);
        if (bill.is_open()) {
            bill << "==================================================" << endl;
            bill << "                Deleted Department Record         " << endl;
            bill << "==================================================" << endl;
            bill << "Deleted Department ID: " << curr->deptId << endl << endl;
            bill << "Deleted Department Name: " << curr->deptName << endl << endl;
            bill.close();
        }	

        prev->next = curr->next;
        delete curr;

        cout << "\n Department Deleted Successfully";
        for (int i = 1; i <= 4; i++) { cout << "."; Sleep(500); }
        cout << endl;
    }

    // Display All Departments
    void displayDepartments() {
        if (!head) {
            cout << "\n No Departments Available.\n";
            return;
        }

        Department* temp = head;

        cout << "\n--------- Departments List ---------\n";
        do {
            cout << " Department ID: " << temp->deptId
                 << ", Name: " << temp->deptName << endl;
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    system("cls");
    cout << R"( 
					     __        __   _                             
					     \ \      / /__| | ___ ___  _ __ ___   ___ 
					      \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \
					       \ V  V /  __/ | (_| (_) | | | | | |  __/
					        \_/\_/ \___|_|\___\___/|_| |_| |_|\___|
				 		
				            +-------------------------------------------+
			                    ¦                                           ¦
			                    ¦       HOSPITAL MANAGEMENT SYSTEM          ¦
			                    ¦                                           ¦
			                    +-------------------------------------------+        
    )" << endl;

    cout << "\n Press Enter to Visit The Menu...";
    getch();

    string MainChoice;

    while (true) {
        displayMainMenu();
        getline(cin, MainChoice);

        if (MainChoice == "1") {
            DoctorManager dm;
            string Choice;
            while (true) {
                ProjectName();
                cout << "\t\t\t------------------------------- Welcome To Doctors Menu -------------------------------" << endl << endl;
                cout << "\t\t\t************************************************************************************" << endl << endl;
                cout << "  1. Add Doctor" << endl;
                cout << "  2. Delete Doctor" << endl;
                cout << "  3. View Doctors" << endl;
                cout << "  0. Return To Main Menu" << endl << endl;
                cout << " Enter your option: ";
                getline(cin, Choice);

                if (Choice == "1") {
                    cout << "\n Press Enter to Continue...";
                    getch();
                    ProjectName();
                    dm.addDoctor();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "2") {
                    ProjectName();
                    dm.deleteDoctor();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "3") {
                    ProjectName();
                    dm.displayDoctors();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "0") break;
                else {
                    cout << " Invalid choice!!";
                    Sleep(1000);
                }
            }
        }
        else if (MainChoice == "2") {
            patient p;
            string Choice;
            while (true) {
                ProjectName();
                cout << "\t\t\t------------------------------- Welcome To Patients Menu -------------------------------" << endl << endl;
                cout << "\t\t\t************************************************************************************" << endl << endl;
                cout << "  1. Add Patient" << endl;
                cout << "  2. Delete Patient" << endl;
                cout << "  3. View Patients" << endl;
                cout << "  0. Return To Main Menu" << endl << endl;
                cout << " Enter your option: ";
                getline(cin, Choice);

                if (Choice == "1") {
                    cout << "\n Press Enter to Continue...";
                    getch();
                    ProjectName();
                    p.pushPatient();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "2") {
                    ProjectName();
                    p.popPatient();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "3") {
                    ProjectName();
                    p.displayStack();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "0") break;
                else {
                    cout << " Invalid choice!!";
                    Sleep(1000);
                }
            }
        }
        else if (MainChoice == "3") {
            Appointment Ap;
            string Choice;
            while (true) {
                ProjectName();
                cout << "\t\t\t--------------------------- Welcome To Appointment Menu ----------------------------" << endl << endl;
                cout << "\t\t\t************************************************************************************" << endl << endl;
                cout << "  1. Book Appointments" << endl;
                cout << "  2. Serve Appointments" << endl;
                cout << "  3. View Appointments" << endl;
                cout << "  0. Return To Main Menu" << endl << endl;
                cout << " Enter your option: ";
                getline(cin, Choice);

                if (Choice == "1") {
                    cout << "\n Press Enter to Continue...";
                    getch();
                    ProjectName();
                    int PId,DId;
                    cout << " Enter The Doctor Id To Book Appointment: ";
                    cin >> DId;
                    cin.ignore();
                    cout << " Enter The Patient Id To Book Appointment: ";
                    cin >> PId;
                    cin.ignore();
                    Ap.AppointmentEnqueue(PId, DId);
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "2") {
                    ProjectName();
                    Ap.AppointmentDequeue();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "3") {
                    ProjectName();
                    Ap.displayAppointments();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "0") break;
                else {
                    cout << " Invalid choice!!";
                    Sleep(1000);
                }
            }
        }
        else if (MainChoice == "4") {
            MedicalReport MR;
            string Choice;
            while (true) {
                ProjectName();
                cout << "\t\t\t-------------------------- Welcome To Medical Reports Menu ---------------------------\n\n";
                cout << "\t\t\t************************************************************************************\n\n";
                cout << "  1. Add Medical Report\n";
                cout << "  2. Search Medical Report\n";
                cout << "  3. View Medical Reports\n";
                cout << "  0. Return To Main Menu\n\n";
                cout << " Enter your option: ";
                getline(cin, Choice);

                if (Choice == "1") {
                    cout << "\n Press Enter to Continue...";
                    getch();
                    ProjectName();
                    MR.addReport();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "2") {
                    ProjectName();
                    MR.findReport();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "3") {
                    ProjectName();
                    MR.displayReports();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "0") break;
                else {
                    cout << " Invalid choice!!";
                    Sleep(1000);
                }
            }
        }
        else if (MainChoice == "5") {
            DepartmentManager DP;
            string Choice;
            while (true) {
                ProjectName();
                cout << "\t\t\t-------------------------- Welcome To Department Menu ---------------------------\n\n";
                cout << "\t\t\t************************************************************************************\n\n";
                cout << "  1. Add Department\n";
                cout << "  2. Delete Department\n";
                cout << "  3. View Departments\n";
                cout << "  0. Return To Main Menu\n\n";
                cout << " Enter your option: ";
                getline(cin, Choice);

                if (Choice == "1") {
                    cout << "\n Press Enter to Continue...";
                    getch();
                    ProjectName();
                    DP.addDepartment();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "2") {
                    ProjectName();
                    DP.deleteDepartment();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "3") {
                    ProjectName();
                    DP.displayDepartments();
                    cout << "\n Press Enter to continue...";
                    getch();
                }
                else if (Choice == "0") break;
                else {
                    cout << " Invalid choice!!";
                    Sleep(1000);
                }
            }
        }
        else if (MainChoice == "0") {
            cout << "\nExiting the program";
            for (int i = 0; i < 3; i++) {
                cout << ".";
                Sleep(700);
            }
            break;
        }
        else {
            cout << "\nInvalid input! Please enter a number from 0-5.\n";
            Sleep(1000);
        }
    }
    return 0;
}
