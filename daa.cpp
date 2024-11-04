#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci numbers
int recursive_fibonacci(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

// Function to print Fibonacci series using recursion
void print_recursive_fibonacci_series(int n)
{
    cout << "Fibonacci series using recursion: ";
    for (int i = 0; i < n; i++) {
        cout << recursive_fibonacci(i) << " ";
    }
    cout << endl;
}

// Function to print Fibonacci series using iteration
void print_iterative_fibonacci_series(int n)
{
    int prev1 = 0, prev2 = 1, curr = 0;

    cout << "Fibonacci series using iteration: ";
    if (n >= 1) cout << prev1 << " ";
    if (n >= 2) cout << prev2 << " ";

    for (int i = 3; i <= n; i++)
    {
        curr = prev1 + prev2;
        cout << curr << " ";
        prev1 = prev2;
        prev2 = curr;
    }
    cout << endl;
}

// Menu-driven main function
int main()
{
    int choice, n;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Print Fibonacci Series using Iteration\n";
        cout << "2. Print Fibonacci Series using Recursion\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of terms in the Fibonacci series: ";
            cin >> n;
            print_iterative_fibonacci_series(n);
            break;

        case 2:
            cout << "Enter the number of terms in the Fibonacci series: ";
            cin >> n;
            print_recursive_fibonacci_series(n);
            break;

        case 3:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid choice! Please select again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}

// Fibonacci Series using Iteration and Recursion
// Iteration :
// Time Complexity = O(N)
// Space Complexity : O(1)
// Recursion :
// Time Complexity : O(1.618^N)
// Space Complexity : O(N) due to Auxilliary Stack Space
// Time Complexity is derived using Binet's Formula



#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node class for Huffman Tree
class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) {
        data = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator to create a min-heap based on frequency
class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Function to build Huffman Tree and generate codes
void buildHuffmanTree(char data[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        
        pq.push(newNode);
    }

    printCodes(pq.top(), "");
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {50, 10, 30, 5, 3, 2};

    buildHuffmanTree(data, freq, 6);
    return 0;
}
//Complexity Analysis :
//Time complexity: O(nlogn) where n is the number of unique characters.
//If there are n nodes, extractMin() is called 2*(n – 1) times. 
//extractMin() takes O(logn) time as it calls minHeapify(). So, overall time complexity is O(nlogn).
//Space Complexity is O(n) 
//Where n is the number of Unique Characters



#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<int>& solution) {
    for (int i = 0; i < row; i++) {
        if (solution[i] == col || solution[i] - i == col - row || solution[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(int row, int n, vector<int>& solution, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solution[i] == j) {
                    cout << "Q ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, solution)) {
            solution[row] = col;
            solveNQueensUtil(row + 1, n, solution, count);
        }
    }
}

void solveNQueens(int n, int firstRow, int firstCol) {
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid position for the first queen." << endl;
        return;
    }

    vector<int> solution(n, -1);
    int count = 0;
    solution[firstRow] = firstCol;  
    solveNQueensUtil(0, n, solution, count);  // Start from the first row

    if (count == 0) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Total solutions: " << count << endl;
    }
}

int main() {
    int n, firstRow, firstCol;
    cout << "Enter the number of queens: ";
    cin >> n;
    cout << "Enter the row (0 to " << n-1 << ") for the first queen: ";
    cin >> firstRow;
    cout << "Enter the column (0 to " << n-1 << ") for the first queen: ";
    cin >> firstCol;

    solveNQueens(n, firstRow, firstCol);
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
  public:
      static  bool cmp(struct Item a, struct Item b)
  {
      double a1=(double)a.value/(double) a.weight;
      double b1=(double)b.value/(double) b.weight;
      return a1>b1;
  }

    double fractionalKnapsack(int w, Item arr[], int n) {
  
      
        sort(arr,arr+n,cmp);
        double ans=0.0;
        
        for(int i=0;i<n;i++)
        {
            if(w>=arr[i].weight)
            {
                ans+=arr[i].value;
                w-=arr[i].weight;
            }
            else
            {
                double fraction=(double)w/(double)arr[i].weight;
                ans+= arr[i].value*fraction;
                break;
            }
            
        }
        
        return ans;
    }
};


int main() {
 
        int n, W;
        cout<<"Enter total no. of weights:- ";
        cin >> n;
        cout<<"Enter the max weight:-";
        cin>>W;

        Item arr[n];
       
        for (int i = 0; i < n; i++) {
            cout<<"Enter profit and its weight:-";
            cin >> arr[i].value >> arr[i].weight;
            
        
}
        
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    
    return 0;
}





//0-1 knapsack using dynamic programming
//1) memoization
#include<bits/stdc++.h>
using namespace std;
    int dp[101][1001];

class Solution
{
    public:

    int knapsack(int W, int wt[], int val[], int n){
        if(n==0 ||  W==0)
            return 0;

        if(dp[n][W]!=-1)
            return dp[n][W];

        if(wt[n-1]<=W)
        {
            int choose=val[n-1]+knapsack(W-wt[n-1],wt,val,n-1);
            int skip=knapsack(W,wt,val,n-1);
            return dp[n][W]=max(choose,skip);
        }
        else{
            return dp[n][W]=knapsack(W,wt,val,n-1);
        }
    } 
};

int main()
{
    int n, W;
    memset(dp,-1,sizeof(dp));
        cout<<"Enter total no. of weights:- ";
        cin >> n;
        cout<<"Enter the max weight:-";
        cin>>W;
        int wt[n];
        int val[n];
       
        for (int i = 0; i < n; i++) {
            cout<<"Enter profit and its weight:-";
            cin >> val[i]>>wt[i];
}
        
        Solution ob;
        cout << "Max profit:- "<<ob.knapsack(W,wt,val,n);
}




#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
using namespace std;

void printArray(const vector<int>& arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int deterministic_partition(vector<int>& arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

int randomized_partition(vector<int>& arr, int low, int high)
{
    int pivotIndex = rand() % (high - low + 1) + low; // Corrected range for pivot
    swap(arr[low], arr[pivotIndex]);
    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }
        while (arr[j] > pivot && j > low)
        {
            j--;
        }

        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void deterministicQuickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int p = deterministic_partition(arr, low, high);
        deterministicQuickSort(arr, low, p - 1);
        deterministicQuickSort(arr, p + 1, high);
    }
}

void randomizedQuickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int p = randomized_partition(arr, low, high);
        randomizedQuickSort(arr, low, p - 1);
        randomizedQuickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int choice;
    cout << "Choose sorting method:\n1. Deterministic Quick Sort\n2. Randomized Quick Sort\n";
    cin >> choice;

    cout << "Given Array: ";
    printArray(arr);

    switch (choice)
    {
        case 1:
            deterministicQuickSort(arr, 0, n - 1);
            cout << "Sorted Array (Deterministic Quick Sort): ";
            printArray(arr);
            break;

        case 2:
            randomizedQuickSort(arr, 0, n - 1);
            cout << "Sorted Array (Randomized Quick Sort): ";
            printArray(arr);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}


// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Student_Management {

    struct Student {
        int stud_id;
        string stud_Name;
        string department;
    }

    Student[] Students;

    // Function to add a new student
    function add_student_detail(int stud_id, string memory stud_Name, string memory department) public {
        Student memory stud_Data = Student(stud_id, stud_Name, department);
        Students.push(stud_Data);
    }

    // Function to get student details by student ID
    function getStudent_detail(int stud_id) public view returns(string memory, string memory) {
        for (uint i = 0; i < Students.length; i++) {
            Student memory stud = Students[i];
            if (stud.stud_id == stud_id) {
                return (stud.stud_Name, stud.department);
            }
        }
        return ("Not Found", "Not Found");
    }

    // Additional function to get the number of students
    function get_student_count() public view returns (uint) {
        return Students.length;
    }

    // Additional function to get the total gas used for adding students
    function estimate_gas_for_add(int stud_id, string memory stud_Name, string memory department) public returns (uint256) {
        uint256 startGas = gasleft();
        
        // Call the add_student_detail function to measure gas used
        add_student_detail(stud_id, stud_Name, department);
        
        uint256 gasUsed = startGas - gasleft();
        return gasUsed;
    }

    // Receive function to accept Ether with no data
    receive() external payable {
        // Custom logic, if any, for receiving Ether
    }

    // Fallback function for non-existent function calls or Ether transfers with data
    fallback() external payable {
        revert("Function not found or contract does not accept Ether with data.");
    }
}





// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleBank 
{
    uint256 private balance;

    event Deposited(uint256 amount);
    event Withdrawn(uint256 amount);

    function deposit(uint256 amount) public {
        balance += amount;
        emit Deposited(amount);
    }

    function withdraw(uint256 amount) public {
        require(amount <= balance, "Insufficient balance");
        balance -= amount;
        emit Withdrawn(amount);
    }

    function displayBalance() public view returns (uint256) {
        return balance;
    }
}

//emit triggers an event to log data.
//event is a logging mechanism that can be subscribed to by external listeners.
//require checks if a condition is met; if not, it reverts the transaction and prevents further execution.
