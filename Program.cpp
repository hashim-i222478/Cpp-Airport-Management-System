// -------------------------------------- NUCES Airline Flight System -----------------------------------------
//HashimAhmad_i222478
//SE-E

#include<iostream>
#include<string.h>
#include<string>
#include<ctime>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#include <unistd.h>
#include <termios.h>

using namespace std;

bool login = false;
int Max_E_pas = 50;
int Max_B_pas = 20;

// Helper function to get a single character without echo (replacement for _getch)
char getch() {
	struct termios oldt, newt;
	char ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

// Helper function to clear the screen (cross-platform)
void clear_screen() {
	// ANSI escape code to clear screen
	std::cout << "\033[2J\033[1;1H";
}

// Helper function to sleep in milliseconds (cross-platform)
void sleep_ms(int milliseconds) {
	usleep(milliseconds * 1000); // usleep takes microseconds
}

string make_password(string& pass) {
	char ch;
	bool is_valid = true;
	int s = 0, u = 0, l = 0, n = 0;
	int pass_length = 0;
	int x = 0;
	string u_pass;
	do {
		is_valid = true;
		pass = "";
		s = u = l = n = 0;
		ch = getch();
		while (ch != '\n' && ch != 13) { // character 13 is enter key
			pass.push_back(ch);
			cout << '*';
			ch = getch();
		}
		cout << endl;
		pass_length = pass.length();
		for (int i = 0; i < pass_length; i++) {
			if (islower(pass[i]))
				l++;
			else if (isupper(pass[i]))
				u++;
			else if (isdigit(pass[i]))
				n++;
			else if (!isalpha(pass[i]) && !isdigit(pass[i]))
				s++;
		}
		if (s == 0 || u == 0 || l == 0 || n == 0 || pass_length < 8) {
			cout << "\nWeak Password!. Please retry\n";
			cout << "\nEnter password: ";
			is_valid = false;
		}
	} while (is_valid == false);
	return pass;
}

class User {
private:

	int user_ID;
	string user_password;
	
public:

	User() {
		user_ID = 0;
		user_password = "";
	}

	User(int user_ID, string user_password) {

		this->user_ID = user_ID;
		this->user_password = user_password;
		
	}

	int getuser_ID() {
		return user_ID;
	}

	string getuser_pass() {
		return user_password;
	}

	void setuser_ID(int ID) {
		user_ID = ID;
	}

	void setuser_password(string user_password) {
		this->user_password == user_password;
	}

};
int b=50;
class Passenger:public User {
protected:

	string passenger_CNIC_no;
	string passenger_passport_no;
	int passenger_age;
	bool visa;
	

public:

	static int ID;
	
	Passenger() {
		
	}

	Passenger(string passenger_CNIC_no, string passenger_passport_no, int passenger_age, bool visa) {
		this->passenger_CNIC_no = passenger_CNIC_no;
		this->passenger_passport_no = passenger_passport_no;
		this->passenger_age = passenger_age;
		this->visa = visa;	
	}

	bool get_passenger_visa() {
		return visa;
	}

	void set_passenger_visa(bool visa) {
		this->visa = visa;
	}

	int get_passenger_age() {
		return passenger_age;
	}

	void set_passenger_age(int passenger_age) {
		this->passenger_age = passenger_age;
	}

	string getpassenger_CNIC() {
		return passenger_CNIC_no;
	}

	string getpassenger_passport() {
		return passenger_passport_no;
	}

	void setpassenger_passport(string passenger_passport_no) {
		this->passenger_passport_no = passenger_passport_no;
	}

	void setpassenger_CNIC(string passenger_CNIC_no) {
		this->passenger_CNIC_no = passenger_CNIC_no;
	}

	
};


class Admin : public User {
	
	string AirLine_Inq_details = "\t\t\tWelcome to NUCES Airline Flight System\nOur System has a network of 10 airports in 5 different cities\nWe have alink with 25 countries in the world\nWe could take you to any place at any time at reasonable prices";

public:

	Admin() {
		//cout << "\t\t\tWelcome to NUCES Airline Flight System\nOur System has a network of 10 airports in 5 different cities\nWe have alink with 25 countries in the world\nWe could take you to any place at any time at reasonable prices"<<endl;
	}

	Admin(string d) {
		AirLine_Inq_details = d;
	}

	string getAirline_INQ_Details() {
		return AirLine_Inq_details;
	}

	void setAirline_INQ_Details(string details) {
		AirLine_Inq_details = details;
	}

	void restrict_passengers() {
		int EC_C;
		int BIS_C;
		int option;
		cout << "Select one option to change the number of users"<<endl;
		cout << "1. Change number of passengers in Economy class\n2. Change number of users in Buisiness class" << endl;
		cin >> option;
		switch (option) {
		case 1:
			cout << "\nPlease enter the number of users you want to restrict in Economy class" << endl;
			cin >> EC_C;
			Max_E_pas = EC_C;
			break;

		case 2:
			cout << "\nPlease enter the number of users you want to restrict in Buisiness class" << endl;
			cin >> BIS_C;
			Max_B_pas = BIS_C;
			break;

		default:
			break;
		}

	}

	void Update_INQ_Details() {
		string det;
		cout << "Enter new details here" << endl;
		//cin.getline(cin, det);
		cin >> det;
		setAirline_INQ_Details(det);
	}

};

class Login {

	Passenger* passenger;
	Admin* A;
	int* adminid;
	string* adminpass;

public:
	
	static int a;

	Login() {
		passenger = new Passenger;
		A = new Admin;
		++a;
		adminid = new int[5];
		adminpass = new string[5];
	}

	void setadmin_ID_pass() {
		string ad[5] = { "Adm!n123", "@dmin321", "ADMin121","adm!!n221", "admin@321" };
		

		int adid[5] = { 1,2,3,4,5 };
		for (int i = 0; i < 5; i++) {
			adminpass[i] = ad[i];
			adminid[i] = adid[i];
		}
	}

	string get_admin_pass(int i) {
		return adminpass[i];
	}

	int get_admin_id(int i) {
		return adminid[i];
	}

	~Login() {
		delete passenger;
		delete A;
	}

	//void register_dependant_user(Passenger* passenger);
	
	void register_user(Passenger* passenger) {

		int aa;
		passenger[a].setuser_ID(a);
		string Password;
		string RePassword;
		string CNIC;
		int login_ID;
		string login_pass;
		int op;
		

		int c1, c2;

		bool is_CNIC_valid = false;
		int age;
		bool pass = false;

		sleep_ms(1000);
		clear_screen();
		cout << "\t\t\t---- Registration Panel ---- " << endl;
		cout << "\nWelcome to NUCES Airline Flight System." << endl;
		cout << "Please enter your details to register as a new user." << endl;
		cout << "\n";

		cout << "Please enter your valid CNIC (13 digit) number: ";
		cin >> CNIC;

		while (CNIC.length() < 13 || CNIC.length() > 13) {

			cout << "\nCNIC is not valid\nIt must contain 13 digits" << endl;
			cout << "Enter CNIC: ";
			cin >> CNIC;

		}
		if (CNIC.length() == 13) {

			passenger[a].setpassenger_CNIC(CNIC);

		}

		cout << "\nEnter yor age: ";
		cin >> age;
		if (age < 18) {
			cout << "\nYou are under age!\nYou cannot register " << endl;
			cout << "\nGo to register for dependant" << endl;
			cout << "\nPress 1. to go to register for dependant";
			cin >> aa;
			if (aa == 1) {
				sleep_ms(1000);
				clear_screen();
				register_dependant_user(passenger);
			}
		}
		else {
			passenger[a].set_passenger_age(age);
		
			cout << "\nYour ID: " << passenger[a].getuser_ID() << endl;
		

		while (pass == false) {

			cout << "\nEnter password: ";
			make_password(Password);
			cout << "\nRe-enter your password to validate: ";
			make_password(RePassword);
			if (Password == RePassword) {
				passenger[a].setuser_password(Password);
				cout << "\nPassword validated!" << endl;
				pass = true;
			}
			else {
				continue;
			}
			break;
		}
		}
		sleep_ms(1000);
		clear_screen();

		cout << "\n ----- Login Panel -----" << endl;
		cout << "\nPlease enter your User ID: ";
		cin >> login_ID;
		passenger->setuser_ID(login_ID);
		cout << "\nPassword: ";
		cin >> login_pass;
		passenger->setuser_password(login_pass);

		for (int x = 0; x < a; x++) {
			if (passenger[x].getuser_ID() != passenger->getuser_ID()) {
				cout << "\nLogin ID not found!!" << endl;;
				login = false;
			}
			else if (passenger[x].getuser_pass() != passenger->getuser_pass()) {
				cout << "\nPassword not found!!" << endl;
				login = false;
			}
			else {
				cout << "\nLogin Successfull!" << endl;
				login = true;
			}
		}
	}

	void register_dependant_user(Passenger* passenger) {

		int login_ID;
		string login_pass;
		int op;
		bool loginD = false;

		passenger[a].setuser_ID(a);
		string Password;
		string RePassword;
		string CNIC;

		int c1, c2;

		bool is_CNIC_valid = false;
		int age;
		bool pass = false;

		sleep_ms(1000);
		clear_screen();
		cout << "\t\t\t---- Registration for dependant Panel ---- " << endl;
		cout << "\nWelcome to NUCES Airline Flight System." << endl;
		cout << "Please enter your details to register as a new user." << endl;
		cout << "\n";

		cout << "Please enter your valid CNIC (13 digit) number: ";
		cin >> CNIC;

		while (CNIC.length() < 13 || CNIC.length() > 13) {
			cout << "\nCNIC is not valid\nIt must contain 13 digits" << endl;
			cout << "Enter CNIC: ";
			cin >> CNIC;
		}
		if (CNIC.length() == 13) {
			passenger[a].setpassenger_CNIC(CNIC);
		}

		cout << "\nEnter yor age: ";
		cin >> age;
		if (age >= 18) {
			cout << "\nYou are under age!\nYou cannot register " << endl;
			cout << "\nGo to register for adult" << endl;
		}

		passenger[a].set_passenger_age(age);

		cout << "\nYour ID: " << passenger[a].getuser_ID() << endl;

		while (pass == false) {

			cout << "\nEnter password: ";
			make_password(Password);
			cout << "\nRe-enter your password to validate: ";
			make_password(RePassword);
			if (Password == RePassword) {
				passenger[a].setuser_password(Password);
				cout << "\nPassword validated!" << endl;
				pass = true;
			}
			else {
				continue;
			}
			break;
		}
		
		if(login == true){

		sleep_ms(1000);
		clear_screen();

		cout << "\n ----- Login Panel -----" << endl;
		cout << "\nPlease enter your User ID: ";
		cin >> login_ID;
		passenger->setuser_ID(login_ID);
		cout << "\nPassword: ";
		cin >> login_pass;

		passenger->setuser_password(login_pass);

		for (int x = 0; x < a; x++) {
			if (passenger[x].getuser_ID() != passenger->getuser_ID()) {
				cout << "\nLogin ID not found!!" << endl;;
				login = false;
			}
			else if (passenger[x].getuser_pass() != passenger->getuser_pass()) {
				cout << "\nPassword not found!!" << endl;
				login = false;
			}
			else {
				cout << "\nLogin Successfull!" << endl;
				login = true;
			}
		}
		
		}

	}

	
	void Login_ADMIN(Admin* ad) {

		int login_ID;
		string login_pass;
		int op;
		char c;
		do {

		cout << "\n ----- Administrator Login Panel -----" << endl;
		cout << "\nPlease enter your User ID: ";
		cin >> login_ID;
		ad->setuser_ID(login_ID);
		cout << "\nPassword: ";
		cin >> login_pass;
		ad->setuser_password(login_pass);
		
		setadmin_ID_pass();

		for (int x = 0; x < 5; x++) {
			if (get_admin_id(x)!=login_ID) {
				cout << "\nLogin ID not found!!" << endl;
				cout << "\nPlease enter your User ID: ";
				cin >> login_ID;
			}
			else if (get_admin_pass(x) != login_pass) {
				cout << "\nPassword not found!!" << endl;
				cout << "\nPassword: ";
				cin >> login_pass;
			}
			cout << "\nYou have been successfully logged in\n";
			break;
		}
		cout << "Do you want to go back to main menu? (y, n)" << endl;
		cin >> c;
		sleep_ms(1000);
		clear_screen();

		} while (c =='n' || c=='N');
	}
	
};

int Login::a = 0;

void PASSENGER_MENU(Passenger* P, Login *l) {
	
	bool op = false;
	int option;
	char a;

	while(op==false){
		sleep_ms(1000);
		clear_screen();
	cout << "PASSENGER PANEL\n";
	cout << "Press 1 to register\n";
	cout << "Press 2 to register for dependant\n";
	cout << "Press 0 to exit\n";

	cin >> option;

	switch (option) {
		
	case 1:
		l->register_user(P);
		
		break;

	case 2:
		l->register_dependant_user(P);
		
		break;

	case 0:
		exit(0);

	default:
		break;
	}
	
	cout << "Stay in the passenger panel? (y, n) " << endl;
	
	cin >> a;
		if (a == 'n' || a == 'N') {
			op = true;
		}
	}
}

void ADMIN(Admin *a, Login *l) {

	int OP;
	char con;
	
	l->Login_ADMIN(a);
	
	do {
	
		sleep_ms(1000);
		clear_screen();

		cout << "\t\t\t----- Administrator Panel ----- " << endl;
		
		cout << "1. Restrict the number of passengers in a plane.\n";
		cout << "2. Update airline inquiry details\n";
		cout << "3. Exit Application" << endl;

		cin >> OP;

		sleep_ms(1000);
		clear_screen();

		switch (OP) {
		case 1:
			a->restrict_passengers();
			break;
		case 2:
			a->Update_INQ_Details();
			break;
		case 3:
			sleep_ms(1000);
			clear_screen();

			cout << "\t\t\tTHANK YOU for using NAFS Flight Reservation System" << endl;
			exit(0);
			break;
		default:
			break;
		}

		cout << "\nDo you wish to continue?(y/n)\n";
		cin >> con;

		
	} while (con == 'y' || con == 'Y');

}

class Countries {
private:

	string* country_name;

public:

	Countries() {
		
		country_name = new string[25];
		
	}

	void set_Country_names() {

		int x = 0;

		string c[25] = {"Afghanistan","Bangladesh","Bahrain","Canada","China","Denmark","France","Iraq","India","Italy","Japan",
						"Kuwait","Malaysia","Norway","Oman","Qatar","Saudi Arabia","Spain","Switzerland","Syria","Thailand",
						"United Arab Emirates","United Kingdom","USA","Yemen"};
		
		while (x < 25) {
			country_name[x] = c[x];
			x++;
		}
	
	}

	//Function to get random countries
	string get_random_Country() {
		
		int index;
		index = rand() % 25;
		return country_name[index];

	}

};

class Local_Airport {
	string* airports;
public:

	Local_Airport() {
		
		airports = new string[10];

	}

	void set_Local_Airport() {
		int x = 0;
		
		string local_airport[10] = {"North Islamabad", "South Islamabad", "North Lahore", "South Lahore", "North Peshawar", "South Peshawar", "North Karachi", "South Karachi", "North Quetta", "South Quetta"};
		
		while (x < 10) {
			airports[x] = local_airport[x];
			x++;
		}
	}

	//gets random airport location
	string get_random_airport() {
		int index;
		index = rand() % 10;
		return airports[index];
	}

};



class Flight_Schedule {
private:

	//string flight_no;
	double hrs;
	string arrival_location;
	string departure_location;
	string i_arr_location;
	string i_dep_location;
	double i_arr_time;
	double i_dep_time;
	bool is_local; //local or international flight
	double arrival_time=0.0;
	double departure_time=0.0;
	int available_eco_seats;
	int available_B_seats;
	int flight_no;

public:

	Flight_Schedule() {
		flight_no = 0;
		arrival_time = 0.0;
		departure_time = 0.0;
		available_eco_seats = Max_E_pas;
		available_B_seats = Max_B_pas;
	}

	void set_flight_no(int x) {
		x = x + 1;
		flight_no = x;
	}

	int get_flight_no() {
		return flight_no;
	}

	void set_hrs(double h) {
		hrs = h;
	}

	double get_hrs() {
		return hrs;
	}

	string get_Arr_loc() {
		return arrival_location;
	}

	void set_Arr_loc(string A_L) {
		arrival_location = A_L;
	}

	string get_dep_loc() {
		return departure_location;
	}

	void set_dep_loc(string D_L) {
		departure_location = D_L;
	}

	double get_Arr_time() {
		return arrival_time;
	}

	void set_Arr_time() {
		arrival_time = get_dep_time() + get_hrs();
	}

	double get_dep_time() {
		return departure_time;
	}

	void set_dep_time(double d_T) {
		departure_time = d_T;
	}

	void set_eco_seats() {
		available_eco_seats = rand() % Max_E_pas;
	}

	void set_B_seats() {
		available_B_seats = rand() % Max_B_pas;
	}

	int get_eco_seats() {
		return available_eco_seats;
	}

	int get_B_seats() {
		return available_B_seats;
	}
	
	

	double Local_flight_time(string arr_airport, string dep_airport) {
		
		double flight_time=0.0; //in hrs format

		if (dep_airport == "North Lahore" || dep_airport == "South Lahore") {
			if (arr_airport == "North Islamabad" || arr_airport == "South Islamabad") {
				flight_time = 0.3;
			}
			else if (arr_airport == "North Peshawar" || arr_airport == "South Peshawar") {
				flight_time = 0.48;
			}
			else if (arr_airport == "North Karachi" || arr_airport == "South Karachi") {
				flight_time = 1.35;
			}
			else if (arr_airport == "North Quetta" || arr_airport == "South Quetta") {
				flight_time = 1.13;
			}
		}

		else if (dep_airport == "North Islamabad" || dep_airport == "South Islamabad") {
			if (arr_airport == "North Lahore" || arr_airport == "South Lahore") {
				flight_time = 0.3;
			}
			else if (arr_airport == "North Peshawar" || arr_airport == "South Peshawar") {
				flight_time = 0.24;
			}
			else if (arr_airport == "North Karachi" || arr_airport == "South Karachi") {
				flight_time = 1.23;
			}
			else if (arr_airport == "North Quetta" || arr_airport == "South Quetta") {
				flight_time = 0.52;
			}
		}
		
		else if (dep_airport == "North Peshawar" || dep_airport == "South Peshawar") {
			if (arr_airport == "North Lahore" || arr_airport == "South Lahore") {
				flight_time = 0.48;
			}
			else if (arr_airport == "North Islamabad" || arr_airport == "South Islamabad") {
				flight_time = 0.24;
			}
			else if (arr_airport == "North Karachi" || arr_airport == "South Karachi") {
				flight_time = 1.22;
			}
			else if (arr_airport == "North Quetta" || arr_airport == "South Quetta") {
				flight_time = 0.46;
			}
		}
		
		else if (dep_airport == "North Karachi" || dep_airport == "South Karachi") {
			if (arr_airport == "North Lahore" || arr_airport == "South Lahore") {
				flight_time = 1.35;
			}
			else if (arr_airport == "North Islamabad" || arr_airport == "South Islamabad") {
				flight_time = 1.23;
			}
			else if (arr_airport == "North Peshawar" || arr_airport == "South Peshawar") {
				flight_time = 1.22;
			}
			else if (arr_airport == "North Quetta" || arr_airport == "South Quetta") {
				flight_time = 0.52;
			}
		}
		
		else if (dep_airport == "North Quetta" || dep_airport == "South Quetta") {
			if (arr_airport == "North Lahore" || arr_airport == "South Lahore") {
				flight_time = 1.13;
			}
			else if (arr_airport == "North Islamabad" || arr_airport == "South Islamabad") {
				flight_time = 1.23;
			}
			else if (arr_airport == "North Peshawar" || arr_airport == "South Peshawar") {
				flight_time = 0.46;
			}
			else if (arr_airport == "North Karachi" || arr_airport == "South Karachi") {
				flight_time = 0.52;
			}
		}
		
		return flight_time;
	}

	double Inter_flight_time(string country) {
		
		double  flight_time = 0.0; //in hrs
		
		if (country == "Afganistan") {
			flight_time = 0.47;
		}

		else if (country == "Bangladesh") {
			flight_time = 2.42;
		}

		else if (country == "Yemen") {
			flight_time = 2.94;
		}

		else if (country == "USA") {
			flight_time = 13.54;
		}

		else if (country == "United Kingdom") {
			flight_time = 6.81;
		}

		else if (country == "United Arab Emirates") {
			flight_time = 1.88;
		}
		else if (country == "Thailand") {
			flight_time = 3.94;
		}
		else if (country == "Syria") {
			flight_time = 3.14;
		}
		else if (country == "Switzerland") {
			flight_time = 6.00;
		}
		else if (country == "Spain") {
			flight_time = 7.16;
		}
		else if (country == "Saudi Arabia") {
			flight_time = 2.74;
		}
		else if (country == "Qatar") {
			flight_time = 2.05;
		}
		else if (country == "Oman") {
			flight_time = 1.82;
		}
		else if (country == "Norway") {
			flight_time = 6.05;
		}
		else if (country == "Malaysia") {
			flight_time = 4.92;
		}
		else if (country == "Kuwait") {
			flight_time = 2.31;
		}
		else if (country == "Japan") {
			flight_time = 6.91;
		}
		else if (country == "Italy") {
			flight_time = 5.66;
		}
		else if (country == "India") {
			flight_time = 1.59;
		}
		else if (country == "Iraq") {
			flight_time = 2.67;
		}
		else if (country == "France") {
			flight_time = 6.50;
		}
		else if (country == "Denmark") {
			flight_time = 5.92;
		}
		else if (country == "China") {
			flight_time = 3.60;
		}
		else if (country == "Canada") {
			flight_time = 11.38;
		}
		else if (country == "Bahrain") {
			flight_time = 2.08;
		}

		return flight_time;
	}

	void Display_local_schedule() {
		cout << fixed << setprecision(2);
		
		cout <<  "\t" << get_dep_loc() << "\t\t" <<get_Arr_loc() << "\t\t" << get_hrs() << " hrs" << "\t" << get_dep_time() << "\t\t" << get_Arr_time() << endl;

	}

	void Display_International_schedule() {
		
		cout << fixed << setprecision(2);

		cout  << "\t" << get_dep_loc() << "\t\t" <<get_Arr_loc() << "\t\t" << get_hrs() << " hrs" << "\t" << get_dep_time() << "\t\t" << get_Arr_time() << endl;

		
	}

};


class Airplane {
protected:

	Flight_Schedule* FS;
	Countries C;
	Local_Airport la;

public:

	Airplane() {
		FS = new Flight_Schedule[15];
		C.set_Country_names();
		la.set_Local_Airport();
	}

	Flight_Schedule* make_flight_schedule(string c) {

		srand(time(0));
		string airports;
		string arrival;
		string departure;
		double de_time;
		double flight_time;
		string c_check;
		de_time=0.0;
		double a;
		for (int i = 0; i < 10; i++) {
			departure = c;
			arrival = la.get_random_airport();
			if (departure == arrival) {
				arrival = la.get_random_airport();
			}
			if (c_check == FS[i].get_Arr_loc()) {
				arrival = la.get_random_airport();
			}
			FS[i].set_Arr_loc(arrival);
			FS[i].set_B_seats();
			FS[i].set_eco_seats();
			FS[i].set_dep_loc(departure);
			FS[i].set_dep_time(de_time);
			FS[i].set_flight_no(i);
			
			flight_time = FS[i].Local_flight_time(departure, arrival);
			FS[i].set_hrs(flight_time);
			FS[i].set_Arr_time();
			a = FS[i].get_Arr_time();
			de_time = a + 2.0;
			c_check = FS[i].get_Arr_loc();
		}
		
		string i_departure;
		string i_arrival;
		double i_flight_time;
		double time=0.0;
		string check;

		for (int x = 10; x < 15; x++) {
		
			i_departure = c;
			FS[x].set_dep_loc(i_departure);
			i_arrival = C.get_random_Country();
			if (check == i_arrival) {
				i_arrival = C.get_random_Country();
			}
			FS[x].set_dep_loc(i_departure);
			FS[x].set_Arr_loc(i_arrival);
			i_flight_time = FS[x].Inter_flight_time(i_arrival);
			FS[x].set_hrs(i_flight_time);
			FS[x].set_dep_time(time);
			FS[x].set_Arr_time();
			FS[x].set_flight_no(x);
			time = rand() % 7;
			check = i_arrival;
		}
		return FS;
	}
};


Flight_Schedule* SCHEDULE(Airplane* a) {
	
	string airport;
	char op;
	int opt;
	Flight_Schedule* FS = new Flight_Schedule;
	
	do{
		
		clear_screen();

	cout << "Please select the Airport to show the flight schedule" << endl;
	cout << "\n1. North Islamabad" << endl;
	cout << "2. South Islamabad" << endl;
	cout << "3. North Lahore" << endl;
	cout << "4. South Lahore" << endl;
	cout << "5. North Peshawar" << endl;
	cout << "6. South Peshawar" << endl;
	cout << "7. North Karachi" << endl;
	cout << "8. South Karachi" << endl;
	cout << "9. North Quetta" << endl;
	cout << "10. South Quetta" << endl;

	cin >> opt;
	

	if (opt==1) {

		FS=a->make_flight_schedule("North Islamabad");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 2) {
		FS=a->make_flight_schedule("South Islamabad");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 3) {
		FS=a->make_flight_schedule("North Lahore");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 4) {
		FS=a->make_flight_schedule("South Lahore");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 5) {
		FS=a->make_flight_schedule("North Peshawar");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 6) {
		FS=a->make_flight_schedule("South Peshawar");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 7) {
		FS=a->make_flight_schedule("North Karachi");
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 8) {
		
		FS=a->make_flight_schedule("South Karachi");
		
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 9) {
	
		FS=a->make_flight_schedule("North Quetta");
		
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}
	else if (opt == 10) {
		
		FS=a->make_flight_schedule("South Quetta");
		
		cout << "\t\t\t\tLOCAL FLIGHTS SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int i = 0; i < 10; i++) {
			cout << i + 1;
			FS[i].Display_local_schedule();
		}

		cout << "\n\n";
		cout << "\t\t\t\tINTERNATIONAL FLIGHT SCHEDULE" << endl;
		cout << "\n";
		cout << "\t" << "Departure " << "\t\t" << "Arrival " << "\t" << "Flight time" << "\t" << "Departure time" << "\t" << "Arrival time" << endl;

		for (int x = 10; x < 15; x++) {
			cout << x + 1;
			FS[x].Display_International_schedule();
		}
	}

	cout << "\nDo you wish to go back to Flight Schedule menu? (y, n)" << endl;
	cin >> op;
	
	} while (op == 'y' || op == 'Y');

	return FS;

}

class Payment {

	double flight_cost;
	double local_tax = 0.05;
	double international_tax = 0.1;


public:

	double get_cost() {
		return flight_cost;
	}

	double calculate_local_cost(double hrs) {
		flight_cost = hrs * 10000;
		return flight_cost;
	}

	double calculate_international_cost(double hrs) {
		flight_cost = hrs * 20000;
		return flight_cost;
	}

	friend ostream& operator<<(ostream& out, const Payment& P) {
		out << P.flight_cost;
		return out;
	}

};


class Booking {
	
	Flight_Schedule* FS;
	Airplane* A;
	Passenger* p;
	Payment pay;

public:

	Booking() {
		FS = new Flight_Schedule[15];
		A = new Airplane;
		p = new Passenger;
	}

	void reserve_seat() {
		
		char cont;
		int op;
		int seats;
		int option;
		double hrs;
		int cancelop;
		double refund;

		do{
			cout << "\t\t\tNUCES AIRLINE FLIGHT SYSTEM (NAFS) - FLIGHT SCHEDULE" << endl;
			FS = SCHEDULE(A);
		
		cout << "\n";
		cout << "Select the flight" << endl;
		cin >> option;
		
		sleep_ms(1000);
		clear_screen();
		
		cout << "\t\t\tNUCES AIRLINE FLIGHT SYSTEM (NAFS) - Seat Reservation" << endl;
		
		for (int i = 0; i < 15; i++)
		{
			if (FS[i].get_flight_no() == option) {

				hrs = FS[i].get_hrs();
				
				cout << "\nFlight no: " << FS[i].get_flight_no() << " selected" << endl;
				cout << "\nDeparture Airport: " << FS[i].get_dep_loc() << endl;
				cout << "Arrival Airport: " << FS[i].get_Arr_loc() << endl;
				cout << "Flight Duration: " << FS[i].get_hrs() << endl;
				cout << "Departure Time: " << FS[i].get_dep_time() << endl;
				cout << "Arrival Time: " << FS[i].get_Arr_time() << endl;
				cout << "\nSelect flight class: " << endl;
				cout << "1. Economy Class\n2. Buisiness Class" << endl;
				cin >> op;
				
				if (op == 1) {
				
					cout << "\nTotal seats available in Economy Class: " << FS[i].get_eco_seats() << endl;
					cout << "How many seats you want to reserve?" << endl;
					cin >> seats;
					
					if (seats <= FS[i].get_eco_seats()) {
						cout << "\nFlight reserved" << endl;
						cout <<"\n" << seats << " Seats reserved" << endl;
						if (i >= 0 && i <= 10) {

							cout << "\nYour payment details are as follows" << endl;
							pay.calculate_local_cost(hrs);
							cout << "Your total cost is: " << pay; //using overloaded operator to display the payment
							 
						}
						else if (i >= 10 && i <= 15) {
					
							cout << "\nYour payment details are as follows" << endl;
							pay.calculate_international_cost(hrs);
							cout << "\nYour total cost is: " << pay; //using overloaded operator to display the payment
						}
					}

					else {
						cout << "\n" << "Sorry! We dont have enough seats" << endl;
					}

				}
				else if (op == 2) {
				
					cout << "\n" << "Total seats available in Buisiness Class: " << FS[i].get_B_seats() << endl;
					cout  << "How many seats you want to reserve?" << endl;
					cin >> seats;
					
					if (seats <= FS[i].get_B_seats()) {
					
						cout << "\nFlight has been booked" << endl;
						cout << "\n" << seats << " Seats reserved" << endl;
						
						if (i >= 0 && i <= 10) {

							cout << "\nYour payment details are as follows" << endl;
							pay.calculate_local_cost(hrs);
							cout << "Your total cost is: " << pay << endl; //using overloaded operator to display the payment
							
						}
						else if (i >= 10 && i <= 15) {

							cout << "\nYour payment details are as follows" << endl;
							pay.calculate_international_cost(hrs);
							cout << "\nYour total cost is: " << pay << endl; //using overloaded operator to display the payment
							
						}
						
					}
					else {
						cout << "\n" << "Sorry! We dont have enough seats" << endl;
					}
				}
			
				cout << "\nPress 1 to cancel the booked flight\nPress 2 to continue" << endl;
				cin >> cancelop;
				
				if (cancelop == 1) {
					cout << "\nYou have been given 25% penalty on your total payement" << endl;
					refund = pay.calculate_local_cost(hrs) * 0.25;
					cout << "Payement refunded: " << refund;
				}
				break;
			}

		}
			
		cout << "\nDo you want to stay in the seat reservation Panel? (y, n)" << endl;
		cin >> cont;
		
		sleep_ms(1000);
		clear_screen();

		} while (cont == 'y' || cont == 'Y');
	}

	void Search_flight() {

		string n;
		char opt;

		FS = SCHEDULE(A);

		do{

			cout << "\nSearch Flights" << endl;
			cout << "\nEnter the arrival location to search: " << endl;
			//getline(cin, n);
			cin >> n;

			for (int i = 0; i < 15; i++) {
				
				if ( n == FS[i].get_Arr_loc()  ) {
					cout << "Flight found" << endl;
					sleep_ms(1000);
					break;
				}
				else {
					cout << "Flight not found" << endl;
					sleep_ms(1000);
					break;			
				}
			}
			cout << "\nDo you want to keep searching for flights?" << endl;
			cin >> opt;
		
		} while (opt == 'y' || opt == 'Y');

	}

};

void Book_Flight(Booking* B) {
	
	char AA;
	int opt;

	do {
		sleep_ms(1000);
		clear_screen();

		cout << "\t\t\tNUCES AIRLINE FLIGHT SYSTEM (NAFS) - Booking Panel" << endl;
		cout << "\n";
		cout << "1. Reserve seat" << endl;
		cout << "2. Search Flights" << endl;
		cout << "3. Exit the application" << endl;
		
		cin >> opt;
	
		if (opt == 1) {
			B->reserve_seat();
		}
		else if (opt == 2) {
			B->Search_flight();
		}
		else if (opt == 3) {
			cout << "\t\t\tTHANK YOU for using NAFS Flight Reservation System" << endl;
			exit(0);
		}
		
		cout << "\nDo you want to go back to the booking panel?(y, n)" << endl;
		cin >> AA;
	
	} while (AA == 'y' || AA == 'y');
}

int Passenger::ID = 0;

int main() {

	int op;
	char cont;

	Login* l = new Login;
	Passenger* p = new Passenger[50000];
	Admin* a = new Admin[50];
	Booking* B = new Booking;
	Airplane* A = new Airplane[10];

	do {

		cout << "\t\t\t----- Welcome to NAFS-NUCES AIRLINE FLIGHT RESERVATION SYSTEM -----" << endl;
		cout << "\nOur system has a network with 25 countries worldwide and we operate in 5 countries nationwide" << endl;
		cout << "NAFS provides you cost effective tickets of your journey's" << endl;

		cout << "\n\nDo you want to continue as a\n1. ADMINISTRATOR\n2. Passenger" << endl;
		cout << "3. Show Flight Schedule" << endl;
		cout << "4. Book flight" << endl;
		cout << "5. Exit application" << endl;

		cin >> op;
		if (op == 1) {
			ADMIN(a, l);
		}
		else if (op == 2) {
			PASSENGER_MENU(p, l);
		}
		else if (op == 3) {
			SCHEDULE(A);
		}
		else if (op == 4) {
			if (login == true) {
				Book_Flight(B);
			}
			else {
				cout << "\nRegister yourself to book a flight" << endl;
			}
		}
		else if (op == 5) {
			cout << "\n\t\t\tTHANK YOU for using NAFS Flight Reservation System" << endl;
			exit(0);
		}

		cout << "Go back to main menu? (y, n)\n" << endl;
		cin >> cont;

		sleep_ms(1000);
		clear_screen();

	} while (cont == 'y' || cont == 'Y');

}