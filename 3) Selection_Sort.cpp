#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Kindly enter the " << n << " numbers" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    selectionSort(v);
    cout << "Here is your sorted array : " << endl;
    for(auto i : v)
    {
        cout << i << " ";
    }
}
