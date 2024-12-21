//#include <iostream>
//#include <string>
//#include <iomanip>
//#include<vector>
//#include<cctype>
//#include<fstream>
//using namespace std;
//const string ClientsFileName = "Client.txt";
//struct sClient
//{
//	string AccountNumber;
//	string PinCode;
//	string Name;
//	string Phone;
//	double AccountBalance;
//	bool MarkForUpdate = false;
//	bool MarkForDelete = false;
//};
//
//string ReadClientAccountNumber()
//{
//	string AccountNumber = "";
//	cout << "\nPlease enter AccountNumber? ";
//	cin >> AccountNumber;
//	return AccountNumber;
//}
//int ReadRangedNumber(int From, int To) {
//	int Number = 0;
//	do
//	{
//		cout << "Enter Number Between " << From;
//		cout << " And " << To << endl;
//		cin >> Number;
//		while (cin.fail())
//		{
//			// user didn't input a number
//			cin.clear();
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			cout << "Invalid Number, Enter a valid one:" << endl;
//			cin >> Number;
//		}
//	} while (Number <From || Number>To);
//	return Number;
//}
//void MenuService() {
//	cout << "________________________________________________________\n";
//	cout << "--------------------------------------------------------\n";
//	cout << "\n\t\tMain Menu Screen \n\n";
//	cout << "________________________________________________________\n";
//	cout << "--------------------------------------------------------\n";
//	cout << "\t[1] Show Client List.";
//	cout << "\n\t[2] Add New Client .";
//	cout << "\n\t[3] Delete Client .";
//	cout << "\n\t[4] Update Client Info .";
//	cout << "\n\t[5] Find Client .";
//	cout << "\n\t[6] Exit.";
//	cout << "\n________________________________________________________\n";
//	cout << "--------------------------------------------------------\n";
//}
//void ProgrameEnds() {
//	system("cls");
//	cout << "\n\n________________________________________________________\n";
//	cout << "\tProgram Ends:-)\n";
//	cout << "--------------------------------------------------------\n";
//}
//vector<string> SplitString(string S1, string Delim)
//{
//	vector<string> vString;
//	short pos = 0;
//	string sWord; // define a string variable
//	// use find() function to get the position of the delimiters
//	while ((pos = S1.find(Delim)) != std::string::npos)
//	{
//		sWord = S1.substr(0, pos); // store the word
//		if (sWord != "")
//		{
//			vString.push_back(sWord);
//		}
//		S1.erase(0, pos + Delim.length());
//	}
//	if (S1 != "")
//	{
//		vString.push_back(S1); // it adds last word of the string.
//	}
//	return vString;
//}
//
//sClient ConvertLinetoRecord(string Line, string Seperator ="#//#")
//{
//	sClient Client;
//	vector<string> vClientData;
//	vClientData = SplitString(Line, Seperator);
//	Client.AccountNumber = vClientData[0];
//	Client.PinCode = vClientData[1];
//	Client.Name = vClientData[2];
//	Client.Phone = vClientData[3];
//	Client.AccountBalance = stod(vClientData[4]);//cast string todouble
//	return Client;
//}
//vector <sClient> LoadCleintsDataFromFile(string FileName)
//{
//	vector <sClient> vClients;
//	fstream MyFile;
//	MyFile.open(FileName, ios::in);//read Mode
//	if (MyFile.is_open())
//	{
//		string Line;
//		sClient Client;
//		while (getline(MyFile, Line))
//		{
//			Client = ConvertLinetoRecord(Line);
//			vClients.push_back(Client);
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//void PrintClientRecord(sClient Client)
//{
//	cout << "| " << setw(15) << left << Client.AccountNumber;
//	cout << "| " << setw(10) << left << Client.PinCode;
//	cout << "| " << setw(40) << left << Client.Name;
//	cout << "| " << setw(12) << left << Client.Phone;
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//}
//void PrintAllClientsData(vector <sClient> vClients)
//{
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
//	cout <<
//		"\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(10) << "Pin Code";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone";
//	cout << "| " << left << setw(12) << "Balance";
//	cout <<
//		"\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//	for (sClient Client : vClients)
//	{
//		PrintClientRecord(Client);
//		cout << endl;
//	}
//	cout <<
//		"\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//}
//void ReturnToMenu() {
//	cout << "Press Any key to Return To Menu...";
//	system("pause>0");
//}
//void ShowAllClient() {
//	system("cls");
//	vector <sClient> vClients =LoadCleintsDataFromFile(ClientsFileName);
//	PrintAllClientsData(vClients);
//	ReturnToMenu();
//	
//}
//void AddNewClientScreen() {
//	system("cls");
//	
//	cout << "\n\n--------------------------------------------------------\n";
//	cout << "\Add New Clients Screen \n";
//	cout << "________________________________________________________\n";
//	cout<<"Adding New Client";
//}
//sClient ClientData(sClient& Client) {
//	cout << "Please Enter Client Data :\n";
//
//	cout << "\nEnter Account Number : ";
//	getline(cin >> ws, Client.AccountNumber);
//	cout << "\nEnter Pin Code : ";
//	getline(cin, Client.PinCode);
//
//	cout << "\nEnter Your Name : ";
//	getline(cin, Client.Name);
//
//	cout << "\nEnter Phone Number : ";
//	getline(cin, Client.Phone);
//
//	cout << "\nEnter Your Balance : ";
//	cin >> Client.AccountBalance;
//	return Client;
//}
//string ConvertRecordToLine(sClient Client, string Seperator ="#//#")
//{
//	string stClientRecord = "";
//	stClientRecord += Client.AccountNumber + Seperator;
//	stClientRecord += Client.PinCode + Seperator;
//	stClientRecord += Client.Name + Seperator;
//	stClientRecord += Client.Phone + Seperator;
//	stClientRecord += to_string(Client.AccountBalance);
//	return stClientRecord;
//}
//void AddDataToFile(string ClientsFile, string Record) {
//	fstream File;
//	File.open(ClientsFile, ios::out | ios::app);
//	if (File.is_open()) {
//		File << Record << endl;
//		File.close();
//	}
//}
//void AddNewClient() {
//	sClient Client;
//	Client = ClientData(Client);
//	AddDataToFile(ClientsFileName, ConvertRecordToLine(Client));
//}
//void AddClient() {
//	AddNewClientScreen();
//	char AddAgain = 'y';
//	do
//	{
//		AddNewClientScreen();
//		AddNewClient();
//
//		cout << "Client Added Successfuly , do you want to Add More Clients ? ";
//		cin >> AddAgain;
//	} while (toupper(AddAgain)=='Y');
//}
//void PrintClientCard(sClient Client)
//{
//	cout << "\nThe following are the client details:\n";
//	cout << "\nAccout Number: " << Client.AccountNumber;
//	cout << "\nPin Code : " << Client.PinCode;
//	cout << "\nName : " << Client.Name;
//	cout << "\nPhone : " << Client.Phone;
//	cout << "\nAccount Balance: " << Client.AccountBalance<<endl;
//}
//bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
//{
//	for (sClient C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			Client = C;
//			return true;
//		}
//	}
//	return false;
//}
//vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out);//overwrite
//	string DataLine;
//	if (MyFile.is_open())
//	{
//		for (sClient C : vClients)
//		{
//			if (C.MarkForDelete == false)
//			{
//				//we only write records that are not marked for delete.
//					DataLine = ConvertRecordToLine(C);
//				MyFile << DataLine << endl;
//			}
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//bool MarkClientForDeleteByAccountNumber(string AccountNumber,vector <sClient>& vClients)
//{
//	for (sClient& C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			C.MarkForDelete = true;
//			return true;
//		}
//	}
//	return false;
//}
//void DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	sClient Client;
//	char Answer = 'n';
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		PrintClientCard(Client);
//		cout << "\n\nAre you sure you want delete this client? y/n ? ";
//		cin >> Answer;
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
//			SaveCleintsDataToFile(ClientsFileName, vClients);
//			//Refresh Clients
//			vClients = LoadCleintsDataFromFile(ClientsFileName);
//			cout << "\n\nClient Deleted Successfully.\n";
//			
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber<< ") is Not Found!\n";
//		
//	}
//	ReturnToMenu();
//}
//void DeleteClientScreen() {
//	system("cls");
//
//	cout << "\n\n--------------------------------------------------------\n";
//	cout << "\Delete Client Screen \n";
//	cout << "________________________________________________________\n";
//}
//void DeleteClient() {
//	DeleteClientScreen();
//	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	DeleteClientByAccountNumber(AccountNumber, vClients);
//}
//sClient ChangeClientRecord(string AccountNumber)
//{
//	sClient Client;
//	Client.AccountNumber = AccountNumber;
//	cout << "\n\nEnter PinCode? ";
//	getline(cin >> ws, Client.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client.Name);
//	cout << "Enter Phone? ";
//	getline(cin, Client.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client.AccountBalance;
//	return Client;
//}
//void UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	sClient Client;
//	char Answer = 'n';
//	if (FindClientByAccountNumber(AccountNumber, vClients,Client))
//	{
//		PrintClientCard(Client);
//		cout << "\n\nAre you sure you want update this client? y/n? ";
//		cin >> Answer;
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			for (sClient& C : vClients)
//			{
//				if (C.AccountNumber == AccountNumber)
//				{
//					C = ChangeClientRecord(AccountNumber);
//					break;
//				}
//			}
//			SaveCleintsDataToFile(ClientsFileName, vClients);
//			cout << "\n\nClient Updated Successfully.\n";
//			
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber
//			<< ") is Not Found!\n";
//		
//	}
//	ReturnToMenu();
//}
//void UpdateClientScreen() {
//	system("cls");
//
//	cout << "\n\n--------------------------------------------------------";
//	cout << "\nUpdate Client Screen \n";
//	cout << "________________________________________________________\n";
//}
//void UpdateClient() {
//	UpdateClientScreen();
//	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	UpdateClientByAccountNumber(AccountNumber, vClients);
//}
//void FindClientScreen() {
//	system("cls");
//
//	cout << "\n\n--------------------------------------------------------";
//	cout << "\nFind Client Screen \n";
//	cout << "________________________________________________________\n";
//}
//void FindClient() {
//	
//	FindClientScreen();
//	sClient Client;
//	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
//	string AccountNumber = ReadClientAccountNumber();
//	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
//	{
//		PrintClientCard(Client);
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << AccountNumber <<
//			") is Not Found!\n";
//	}
//	ReturnToMenu();
//}
//void Services(short Choice) {
//	switch (Choice)
//	{
//	case 1:
//		ShowAllClient();
//		break;
//	case 2:
//		AddClient();
//		break;
//	case 3:
//		DeleteClient();
//		break;
//	case 4:
//		UpdateClient();
//		break;
//	case 5:
//		FindClient();
//		break;
//	case 6:
//		ProgrameEnds();
//		break;
//	}
//}
//void StartService() {
//	short Choice;
//	do
//	{
//		system("cls");
//		MenuService();
//		Choice = ReadRangedNumber(1, 6);
//		Services(Choice);
//			
//	} while (Choice!=6);
//}
//int main()
//{
//	StartService();
//	system("pause>0");
//	return 0;
//}


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Client.txt";

void ShowMainMenue();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double
    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }

        MyFile.close();

    }
    return false;
}

sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    for (sClient& C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }

    }

    return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }

        }

        MyFile.close();
    }

    return vClients;
}

void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        //system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients 
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUpdateClient = 4,
    eFindClient = 5, eExit = 6
};

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();

}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main()

{
    ShowMainMenue();
    system("pause>0");
    return 0;
}
