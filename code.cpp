#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
    int total_boats = 10, total_hours_hired = 0;
    float total_money_taken = 0.0, starting_time = 10.00, ending_time = 17.00, hourly_rate = 20.0, half_hour_rate = 12.0;

    // Array to store profits for each boat
    float boat_profits[10] = { 0.0 };

    cout << "\t\tBoat Hire System\n";

    while (true)
    {
        float payment, start_hour, end_hour, hours_hired;
        int boat_number;

        // Get input for boat number
        cout << "\tEnter the boat number (1 to 10): ";
        cin >> boat_number;

        // Validate boat number
        if (boat_number < 1 || boat_number > total_boats)
        {
            cout << "\tInvalid boat number. Please enter a number between 1 and 10." << endl;
            continue;
        }

        // Get input for start and end time
        cout << "\tEnter the start time (in 24-hour format): ";
        cin >> start_hour;

        // Check if start time is valid
        if (start_hour < starting_time || start_hour > ending_time)
        {
            cout << "\tInvalid start time. No boat can be hired before 10:00 or after 17:00." << endl;
            continue;
        }

        // Check boat availability
        if (boat_profits[boat_number - 1] > 0)
        {
            cout << "\tBoat " << boat_number << " is already hired during the specified time." << endl;
            continue;
        }

        cout << "\tEnter the end time (in 24-hour format): ";
        cin >> end_hour;

        // Check if end time is valid
        if (end_hour < starting_time || end_hour > ending_time || end_hour <= start_hour)
        {
            cout << "\tInvalid end time. No boat can be returned before 10:00, after 17:00, or before the start time." << endl;
            continue;
        }

        // Calculate hours and payment
        hours_hired = end_hour - start_hour;
        total_hours_hired += hours_hired;

        if (hours_hired == 1)
        {
            payment = hourly_rate;
        }
        else if (hours_hired == 0.5)
        {
            payment = half_hour_rate;
        }
        else
        {
            payment = hourly_rate * hours_hired;
        }

        // Update total money taken and individual boat profits
        total_money_taken += payment;
        boat_profits[boat_number - 1] += hours_hired;

        // Output information
        cout << "\tBoat " << boat_number << " hired for " << hours_hired << " hours. Payment: $" << fixed << setprecision(2) << payment << endl;
        cout << "\tTotal money taken for the day: $" << fixed << setprecision(2) << total_money_taken << endl;
        cout << "\tTotal hours hired for the day: " << total_hours_hired << " hours" << endl;
        cout << "\tProfit for Boat " << boat_number << ": $" << fixed << setprecision(2) << boat_profits[boat_number - 1] << endl;

        // Ask if the user wants to continue
        char choice;
        cout << "\tDo you want to hire another boat? (y/n): ";
        cin >> choice;

        if (choice != 'y')
        {
            break;
        }
    }

    // Calculate total money taken, total hours hired, unused boats, and the boat used the most
    float total_money_taken_day = 0.0, total_hours_hired_day = 0.0, max_hours_used = 0;
    int unused_boats = 0, most_used_boat = -1 ;

    for (int i = 0; i < total_boats; ++i)
    {
        total_money_taken_day += boat_profits[i] * hourly_rate;
        total_hours_hired_day += (boat_profits[i] > 0) ? 1 : 0;

        if (boat_profits[i] == 0.0)
        {
            unused_boats++;
        }

        if (boat_profits[i] > max_hours_used)
        {
            max_hours_used = boat_profits[i];
            most_used_boat = i + 1; // Boat numbers are 1-indexed
        }
    }

    cout << "\n\tEnd of the day report:" << endl;
    cout << "\tTotal money taken for the day: $" << fixed << setprecision(2) << total_money_taken_day << endl;
    cout << "\tTotal hours hired for the day: " << total_hours_hired_day << " hours" << endl;
    cout << "\tNumber of boats not used today: " << unused_boats << endl;

    if (most_used_boat != -1)
    {
        cout << "\tBoat " << most_used_boat << " was used the most with " << max_hours_used << " hours." << endl;
    }
    else
    {
        cout << "\tNo boats were used today." << endl;
    }

    // Display individual boat profits
    for (int i = 0; i < total_boats; ++i)
    {
        cout << "\tProfit for Boat " << (i + 1) << ": $" << fixed << setprecision(2) << boat_profits[i] * hourly_rate << endl;
    }

    return 0;
}