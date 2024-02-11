#include <bits/stdc++.h>
using namespace std;

class Timings
{
public:
    string time;
    string screenNumber;
    
};

class Movie
{
public:
    string name;
    string language;
    int duration;
    float imdbRating;
    
    Movie(string n, string l, int d, float r) : name(n), language(l), duration(d), imdbRating(r) {}

    bool operator<(const Movie &m) const
    {
        if (name == m.name)
            return language < m.language;
        else
            return name < m.name;
    }
};

class Theater
{
public:
    string brand;
    float rating;
    string theaterid;
    vector<pair<Movie, vector<Timings>>> allMoviesdetail;
    string location;
    long long totalCollection;
    
    Theater(string b, float r, string id, vector<pair<Movie, vector<Timings>>> m, string loc, long long tc) : brand(b), rating(r), theaterid(id), allMoviesdetail(m), location(loc), totalCollection(tc) {}
};

class City
{
public:
    string city;
    vector<Theater> allTheater;
  
    City(string c) : city(c) {}

    void addTheater()
    {
        string brand;
        float rating;
        string theaterid;
        string location;
        long long totalCollection;
        cout << "Enter theater brand: ";
        cin >> brand;
        cout << "Enter theater rating: ";
        cin >> rating;
        cout << "Enter theater ID: ";
        cin >> theaterid;
        cout << "Enter theater location: ";
        cin >> location;
        cout << "Enter theater total collection: ";
        cin >> totalCollection;
        cout << "Enter number of movies: ";
        int numMovies;
        cin >> numMovies;
        vector<pair<Movie, vector<Timings>>> allMoviesdetail;
        for (int i = 0; i < numMovies; i++)
        {
            string movieName, language;
            int duration;
            float imdbRating;
            cout << "Enter movie name: ";
            cin >> movieName;
            cout << "Enter movie language: ";
            cin >> language;
            cout << "Enter movie duration: ";
            cin >> duration;
            cout << "Enter movie IMDb rating: ";
            cin >> imdbRating;
            Movie m(movieName, language, duration, imdbRating);
            cout << "Enter number of timings: ";
            int numTimings;
            cin >> numTimings;
            vector<Timings> timings(numTimings);
            for (int j = 0; j < numTimings; j++)
            {
                cout << "Enter timing " << j + 1 << " time: ";
                cin >> timings[j].time;
                cout << "Enter timing " << j + 1 << " screen number: ";
                cin >> timings[j].screenNumber;
            }
            allMoviesdetail.push_back({m, timings});
        }
        Theater t(brand, rating, theaterid, allMoviesdetail, location, totalCollection);
        allTheater.push_back(t);
    }

    void displayCityInformation()
    {
        cout << "\nCity: " << city << "\n";
        cout << "------------------------\n";

        for (const Theater &theater : allTheater)
        {
            cout << "\n| Theater Brand | Rating | Theater ID | Location | Total Collection |\n";
            cout << "| ------------- | ------ | ---------- | -------- | ---------------- |\n";
            cout << "| " << theater.brand << "\t\t| " << theater.rating << " \t | " << theater.theaterid << "\t      |" << theater.location << " | " << theater.totalCollection << " \t    |\n";
            cout << "\nMovies Playing:";

            for (const auto &movieDetails : theater.allMoviesdetail)
            {
               
                const Movie &movie = movieDetails.first;
                const vector<Timings> &timings = movieDetails.second;

                cout << "\n  Movie Name: " << movie.name << "\n";
                cout << "  Language: " << movie.language << "\n";
                cout << "  Duration: " << movie.duration << " minutes\n";
                cout << "  IMDb Rating: " << movie.imdbRating << "\n";

                cout << "  Screen Timings:\n";
                for (const Timings &timing : timings)
                {
                    cout << "    Time: " << timing.time << ", Screen: " << timing.screenNumber << "\n";
                }
                
            }

            cout << "\n------------------------\n";
        }
    }
};

class Customer
{
public:
    string name;
    string email;

    Customer(string n, string e) : name(n), email(e) {}
};

class admindetails : public Customer
{
public:
    string password;
    admindetails(string n, string e, string pass) : Customer(n, e), password(pass) {}
    bool checkAdminPassword(string em, string pass)
    {

        if (password == pass && email == em)
        {
            return true;
        }
        return false;
    }
};
// Function to check if a customer is already registered
bool isRegistered(vector<Customer> &customers, string email)
{
    for (Customer &customer : customers)
    {
        if (customer.email == email)
        {
            return true;
        }
    }
    return false;
}

void registerCustomer(vector<Customer> &customers, string name, string email)
{
    if (!isRegistered(customers, email))
    {
        customers.push_back(Customer(name, email));
        cout << "Registration successful.\n";
    }
    else
    {
        cout << "This email is already registered.\n";
    }
}
void deleteCustomer(vector<Customer> &customers, string email)
{
    auto it = remove_if(customers.begin(), customers.end(), [email](const Customer &customer)
                        { return customer.email == email; });

    if (it != customers.end())
    {
        customers.erase(it, customers.end());
        cout << "Customer account deleted successfully.\n";
    }
    else
    {
        cout << "Customer not found in the database.\n";
    }
}

void displayTotalCollection(Theater &theater)
{
    cout << "Total collection of " << theater.brand << " at " << theater.location << " is " << theater.totalCollection << "\n";
}

int main()
{
   

    vector<City> allCity;

    Movie m1("Dangal", "Hindi", 161, 8.4);
    Movie m2("Baahubali 2", "Telugu", 167, 8.2);
    vector<Timings> t1 = {Timings{"9:00", "1"}, Timings{"12:00", "2"}};
    vector<Timings> t2 = {Timings{"15:00", "3"}, Timings{"18:00", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail1 = {{{m1, t1}, {m2, t2}}};
    Theater th1("PVR", 4.5, "T1", allMoviesdetail1, "Location1", 1000000);

    Movie m3("Avengers: Endgame", "English", 180, 8.5);
    Movie m4("Joker", "English", 122, 8.7);
    vector<Timings> t3 = {Timings{"10:00", "1"}, Timings{"13:00", "2"}};
    vector<Timings> t4 = {Timings{"16:00", "3"}, Timings{"19:00", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail2 = {{{m3, t3}, {m4, t4}}};
    Theater th2("INOX", 4.4, "T2", allMoviesdetail2, "Location2", 1200000);

    City c1("Mumbai");
    c1.allTheater.push_back(th1);
    c1.allTheater.push_back(th2);
    allCity.push_back(c1);

    Movie m5("Kabir Singh", "Hindi", 173, 7.1);
    Movie m6("War", "Hindi", 154, 7.2);
    vector<Timings> t5 = {Timings{"10:00", "1"}, Timings{"13:00", "2"}};
    vector<Timings> t6 = {Timings{"16:00", "3"}, Timings{"19:00", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail3 = {{{m5, t5}, {m6, t6}}};
    Theater th3("PVR", 4.2, "T3", allMoviesdetail3, "Location3", 900000);

    Movie m7("Jabariya Jodi", "Hindi", 140, 6.6);
    Movie m8("Super 30", "Hindi", 154, 8.0);
    vector<Timings> t7 = {Timings{"11:00", "1"}, Timings{"14:00", "2"}};
    vector<Timings> t8 = {Timings{"17:00", "3"}, Timings{"20:00", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail4 = {{{m7, t7}, {m8, t8}}};
    Theater th4("INOX", 4.1, "T4", allMoviesdetail4, "Location4", 1000000);

    City c2("Delhi");
    c2.allTheater.push_back(th3);
    c2.allTheater.push_back(th4);
    allCity.push_back(c2);

    Movie m9("Darbar", "Tamil", 167, 7.3);
    Movie m10("Bigil", "Tamil", 178, 7.1);
    vector<Timings> t9 = {Timings{"9:00", "1"}, Timings{"12:00", "2"}};
    vector<Timings> t10 = {Timings{"15:00", "3"}, Timings{"18:00", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail5 = {{{m9, t9}, {m10, t10}}};
    Theater th5("Sathyam Cinemas", 4.3, "T5", allMoviesdetail5, "Location5", 1300000);

    Movie m11("Kaithi", "Tamil", 147, 8.5);
    vector<Timings> t11 = {Timings{"10:30", "1"}, Timings{"13:30", "2"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail6 = {{{m11, t11}}};
    Theater th6("Devi Cineplex", 4.0, "T6", allMoviesdetail6, "Location6", 1000000);

    City c3("Chennai");
    c3.allTheater.push_back(th5);
    c3.allTheater.push_back(th6);
    allCity.push_back(c3);

    Movie m12("Parineeta", "Bengali", 133, 7.6);
    Movie m13("Chhichhore", "Hindi", 146, 8.2);
    vector<Timings> t12 = {Timings{"9:30", "1"}, Timings{"12:30", "2"}};
    vector<Timings> t13 = {Timings{"15:30", "3"}, Timings{"18:30", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail7 = {{{m12, t12}, {m13, t13}}};
    Theater th7("INOX", 4.5, "T7", allMoviesdetail7, "Location7", 1200000);

    Movie m14("Chirodini Tumi Je Amar", "Bengali", 159, 7.9);
    vector<Timings> t14 = {Timings{"10:00", "1"}, Timings{"13:00", "2"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail8 = {{{m14, t14}}};
    Theater th8("Priya Cinema", 4.3, "T8", allMoviesdetail8, "Location8", 1100000);

    City c4("Kolkata");
    c4.allTheater.push_back(th7);
    c4.allTheater.push_back(th8);
    allCity.push_back(c4);

    Movie m15("KGF", "Kannada", 156, 8.5);
    Movie m16("Ugramm", "Kannada", 160, 8.2);
    vector<Timings> t15 = {Timings{"10:30", "1"}, Timings{"13:30", "2"}};
    vector<Timings> t16 = {Timings{"16:30", "3"}, Timings{"19:30", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail9 = {{{m15, t15}, {m16, t16}}};
    Theater th9("PVR", 4.4, "T9", allMoviesdetail9, "Location9", 1400000);

    Movie m17("Bell Bottom", "Kannada", 140, 7.8);
    vector<Timings> t17 = {Timings{"9:00", "1"}, Timings{"12:00", "2"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail10 = {{{m17, t17}}};
    Theater th10("Cinepolis", 4.2, "T10", allMoviesdetail10, "Location10", 1300000);

    City c5("Bangalore");
    c5.allTheater.push_back(th9);
    c5.allTheater.push_back(th10);
    allCity.push_back(c5);

    Movie m18("RRR", "Telugu", 176, 8.7);
    Movie m19("Vakeel Saab", "Telugu", 153, 7.9);
    vector<Timings> t18 = {Timings{"11:00", "1"}, Timings{"14:00", "2"}};
    vector<Timings> t19 = {Timings{"17:00", "3"}, Timings{"20:00", "1"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail11 = {{{m18, t18}, {m19, t19}}};
    Theater th11("INOX", 4.3, "T11", allMoviesdetail11, "Location11", 1100000);

    Movie m20("Pushpa", "Telugu", 167, 8.5);
    vector<Timings> t20 = {Timings{"9:30", "1"}, Timings{"12:30", "2"}};
    vector<pair<Movie, vector<Timings>>> allMoviesdetail12 = {{{m20, t20}}};
    Theater th12("Cinepolis", 4.5, "T12", allMoviesdetail12, "Location12", 1200000);

    City c6("Hyderabad");
    c6.allTheater.push_back(th11);
    c6.allTheater.push_back(th12);
    allCity.push_back(c6);


    vector<admindetails> adm;
    adm.push_back(admindetails("akshat", "sahu", "akshat"));
    adm.push_back(admindetails("akshat", "sa", "akshat"));

    adm.push_back(admindetails("akshat", "sah", "akshat"));

    vector<Customer> cust;
    cust.push_back(Customer("akshat", "sahu"));

ak:
    FILE *ptr = fopen("bookings.txt", "a");
    cout << "ADMIN PLEASE ENTER YOUR LOGIN ID :";
    string m;
    cin >> m;
    cout << "ADMIN PLEASE ENTER YOUR PASSWORD :";

    string x;
    cin >> x;
    string customerName, customerEmail, password;

    for (admindetails &ad : adm)
    {
        if (ad.checkAdminPassword(m, x))

        {
            cout << "--------WELCOME MR/MRS " << ad.name << " BOOKMYSHOW TICKET MANAGMENT SYSTEM-----------\n";
            int choice;
            while (1)
            {
                cout << "\nADMIN MENU\n";
                cout << "1. Add ADMIN\n";
                cout << "2. Add theater in a particular city\n";
                cout << "3. Add movie in a particular theater\n";
                cout << "4. Add customer details\n";
                cout << "5. Check customer registration\n";
                cout << "6. Delete customer account\n";
                cout << "7. Book a ticket\n";
                cout << "8. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
                string customerName, customerEmail, password;
                string cityInput;
                string theaterIDInput;
                if (choice == 1)
                {
                    cout << "Enter admin name: ";
                    cin >> customerName;
                    cout << "Enter admin email: ";
                    cin >> customerEmail;
                    cout << "Enter password: ";
                    cin >> password;
                    adm.push_back(admindetails(customerName, customerEmail, password));
                }
                if (choice == 2)
                {
                    cout << "Enter the city where you want to add a Theater: ";
                    cin >> cityInput;

                    City *selectedCity = nullptr;
                    for (City &city : allCity)
                    {
                        if (city.city == cityInput)
                        {
                            city.addTheater();
                            break;
                        }
                    }
                }
                if (choice == 3)
                {

                    cout << "Enter the city where you want to add a movie: ";
                    cin >> cityInput;

                    City *selectedCity = nullptr;
                    for (City &city : allCity)
                    {
                        if (city.city == cityInput)
                        {
                            selectedCity = &city;
                            break;
                        }
                    }

                    if (selectedCity != nullptr)
                    {
                        cout << "Enter the theater ID where you want to add a movie: ";
                        cin >> theaterIDInput;

                        Theater *selectedTheater = nullptr;
                        for (Theater &theater : selectedCity->allTheater)
                        {
                            if (theater.theaterid == theaterIDInput)
                            {
                                selectedTheater = &theater;
                                break;
                            }
                        }

                        if (selectedTheater != nullptr)
                        {
                            string movieName, language;
                            int duration;
                            float imdbRating;
                            cout << "Enter movie name: ";
                            cin >> movieName;
                            cout << "Enter movie language: ";
                            cin >> language;
                            cout << "Enter movie duration: ";
                            cin >> duration;
                            cout << "Enter movie IMDb rating: ";
                            cin >> imdbRating;

                            Movie m(movieName, language, duration, imdbRating);

                            cout << "Enter number of timings: ";
                            int numTimings;
                            cin >> numTimings;
                            vector<Timings> timings(numTimings);

                            for (int j = 0; j < numTimings; j++)
                            {
                                cout << "Enter timing " << j + 1 << " time: ";
                                cin >> timings[j].time;
                                cout << "Enter timing " << j + 1 << " screen number: ";
                                cin >> timings[j].screenNumber;
                            }

                            selectedTheater->allMoviesdetail.push_back({m, timings});
                            cout << "Movie added successfully!\n";

                            selectedCity->displayCityInformation();
                        }
                        else
                        {
                            cout << "Theater ID not found in the specified city.\n";
                        }
                    }
                    else
                    {
                        cout << "City not found.\n";
                    }
                }
                if (choice == 4)
                {
                    cout << "Enter customer name: ";
                    cin >> customerName;
                    cout << "Enter customer email: ";
                    cin >> customerEmail;
                    registerCustomer(cust, customerName, customerEmail);
                }
                if (choice == 5)
                {
                    cout << "ENTER THE EMAIL ID OF THE CUSTOMER :";

                    cin >> customerEmail;
                    if (isRegistered(cust, customerEmail))
                    {
                        cout << "\nCUSTOMER IS REGISTERED.\n";
                    }
                    else
                    {
                        cout << "\nCUSTOMER NOT FOUND IN DATABASE.\n";
                    }
                }
                if (choice == 6)
                {
                    cout << "Enter customer email: ";
                    cin >> customerEmail;
                    deleteCustomer(cust, customerEmail);
                }
                if (choice == 7)
                {
                    string customerEmail;
                    cout << "Enter customer email: ";
                    cin >> customerEmail;

                    Customer *selectedCustomer = nullptr;
                    for (Customer &customer : cust)
                    {
                        if (customer.email == customerEmail)
                        {
                            selectedCustomer = &customer;
                            break;
                        }
                    }

                    if (selectedCustomer != nullptr)
                    {
                        cout << "Select a city:\n";
                        for (int i = 0; i < allCity.size(); i++)
                        {
                            cout << i + 1 << ". " << allCity[i].city << "\n";
                        }

                        int cityChoice;
                        cin >> cityChoice;

                        if (cityChoice >= 1 && cityChoice <= allCity.size())
                        {
                            City &selectedCity = allCity[cityChoice - 1];

                            cout << "Select a theater:\n";
                            for (int i = 0; i < selectedCity.allTheater.size(); i++)
                            {
                                cout << i + 1 << ". " << selectedCity.allTheater[i].brand << " (" << selectedCity.allTheater[i].theaterid << ")\n";
                                for (const auto &movieDetails : selectedCity.allTheater[i].allMoviesdetail)
                                {
                                    const Movie &movie = movieDetails.first;
                                    const vector<Timings> &timings = movieDetails.second;

                                    cout << "\nMovie Name: " << movie.name << "\n";
                                    cout << "Language: " << movie.language << "\n";
                                    cout << "Duration: " << movie.duration << " minutes\n";
                                    cout << "IMDb Rating: " << movie.imdbRating << "\n";

                                    cout << "Screen Timings:\n";
                                    for (const Timings &timing : timings)
                                    {
                                        cout << "Time: " << timing.time << ", Screen: " << timing.screenNumber << "\n";
                                    }
                                    
                                }
                            }

                            int theaterChoice;
                            cin >> theaterChoice;

                            if (theaterChoice >= 1 && theaterChoice <= selectedCity.allTheater.size())
                            {
                                Theater &selectedTheater = selectedCity.allTheater[theaterChoice - 1];

                                for (const auto &movieDetails : selectedTheater.allMoviesdetail)
                                {
                                    const Movie &movie = movieDetails.first;
                                    const vector<Timings> &timings = movieDetails.second;

                                    cout << "\nMovie Name: " << movie.name << "\n";
                                    cout << "Language: " << movie.language << "\n";
                                    cout << "Duration: " << movie.duration << " minutes\n";
                                    cout << "IMDb Rating: " << movie.imdbRating << "\n";

                                    cout << "Screen Timings:\n";
                                    for (const Timings &timing : timings)
                                    {
                                        cout << "Time: " << timing.time << ", Screen: " << timing.screenNumber << "\n";
                                    }
                                   
                                }

                                cout << "Enter the movie index and timing index to book (e.g., 1 2 for first movie and second timing): ";
                                int movieIndex, timingIndex;
                                cin >> movieIndex >> timingIndex;

                                if (movieIndex >= 1 && movieIndex <= selectedTheater.allMoviesdetail.size() &&
                                    timingIndex >= 1 && timingIndex <= selectedTheater.allMoviesdetail.begin()->second.size())
                                {
                                    const Movie &selectedMovie = selectedTheater.allMoviesdetail[movieIndex - 1].first;
                                    const Timings &selectedTiming = selectedTheater.allMoviesdetail[movieIndex - 1].second[timingIndex - 1];
                                    cout << "Enter the number of tickets:\n";
                                    string numt;
                                    cin >> numt;
                                    cout << "Ticket booked successfully for " << selectedMovie.name << " at " << selectedTiming.time << ", Screen: " << selectedTiming.screenNumber << "\n";
                                    rewind(ptr);
                                    if (ptr != NULL)
                                    {
                                        fputs(customerEmail.c_str(), ptr);
                                        fputc(' ', ptr);
                                        fputs(selectedCity.city.c_str(), ptr);
                                        fputc(' ', ptr);
                                        fputs(selectedTheater.brand.c_str(), ptr);
                                        fputc(' ', ptr);
                                        fputs(selectedMovie.name.c_str(), ptr);
                                        fputc(' ', ptr);
                                        fputs(selectedTiming.time.c_str(), ptr);
                                        fputc(' ', ptr);
                                        fputs(numt.c_str(), ptr);
                                        fputc(' ', ptr);
                                        fputc('\n', ptr);

                                        rewind(ptr);
                                       
                                    }
                                    else
                                    {
                                      
                                        perror("Error opening file");
                                    }
                                }
                                else
                                {
                                    cout << "Invalid movie or timing index.\n";
                                }
                            }
                            else
                            {
                                cout << "Invalid theater index.\n";
                            }
                        }
                        else
                        {
                            cout << "Invalid city index.\n";
                        }
                    }
                    else
                    {
                        cout << "Customer not found in the database.\n";
                    }
                }
                if (choice == 8)
                {
                   
                    goto ak;
                    fclose(ptr);
                }
                if (choice == 9)
                // {
                //     // Exit
                //     goto ak;
                //     fclose(ptr);
                // }
                if (!(0 < choice < 9))
                {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        }
    }
}