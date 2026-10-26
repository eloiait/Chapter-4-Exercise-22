#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Named constants for the data plans
    const double PLAN_A_COST = 39.99;
    const double PLAN_B_COST = 59.99;
    const double PLAN_C_COST = 79.99;
    const double EXTRA_GB_COST = 8.00;

    const int PLAN_A_DATA = 2;
    const int PLAN_B_DATA = 8;

    // Variables
    char plan;
    double gigabytes;
    double totalBill;
    double planACost;
    double planBCost;
    double planCCost;

    // Get customer information
    cout << "Mobile Service Provider Billing Program" << endl;
    cout << "----------------------------------------" << endl;

    cout << "Enter the plan purchased (A, B, or C): ";
    cin >> plan;

    plan = toupper(plan);

    cout << "Enter the number of gigabytes used: ";
    cin >> gigabytes;

    // Validate input
    if (gigabytes < 0 || (plan != 'A' && plan != 'B' && plan != 'C'))
    {
        cout << "Invalid input. Please enter a valid plan and data usage."
            << endl;
        return 1;
    }

    // Calculate the cost of each plan for the customer's usage
    planACost = PLAN_A_COST;

    if (gigabytes > PLAN_A_DATA)
    {
        planACost += (gigabytes - PLAN_A_DATA) * EXTRA_GB_COST;
    }

    planBCost = PLAN_B_COST;

    if (gigabytes > PLAN_B_DATA)
    {
        planBCost += (gigabytes - PLAN_B_DATA) * EXTRA_GB_COST;
    }

    planCCost = PLAN_C_COST;

    // Calculate the selected plan's bill
    if (plan == 'A')
    {
        totalBill = planACost;
    }
    else if (plan == 'B')
    {
        totalBill = planBCost;
    }
    else
    {
        totalBill = planCCost;
    }

    // Display the bill
    cout << fixed << setprecision(2);
    cout << "\n========== MONTHLY BILL ==========" << endl;
    cout << "Plan purchased: Plan " << plan << endl;
    cout << "Gigabytes used: " << gigabytes << " GB" << endl;
    cout << "Total amount due: $" << totalBill << endl;

    // Display potential savings
    cout << "\n========== POTENTIAL SAVINGS ==========" << endl;

    if (plan == 'A')
    {
        if (planACost > planBCost)
        {
            cout << "Savings by switching to Plan B: $"
                << planACost - planBCost << endl;
        }

        if (planACost > planCCost)
        {
            cout << "Savings by switching to Plan C: $"
                << planACost - planCCost << endl;
        }
    }
    else if (plan == 'B')
    {
        if (planBCost > planCCost)
        {
            cout << "Savings by switching to Plan C: $"
                << planBCost - planCCost << endl;
        }
    }

    cout << "======================================" << endl;

    return 0;
}