//  -------------- introduction of 2D array ----------------------------

2D array, also known as a two-dimensional array or a matrix, is a data structure used to store elements in a tabular format,
  organized into rows and columns. It can be conceptually viewed as an "array of arrays," where each element within 
the array is itself another array.
Key characteristics of 2D arrays in C++:
Structure:
Data is arranged in a grid-like pattern, similar to a spreadsheet, with elements identified by both a row index and a column index.
Declaration:
A 2D array is declared by specifying the data type, the array name, and two sets of square brackets for the dimensions
(number of rows and number of columns).

    int matrix[3][4]; // Declares a 2D array named 'matrix' with 3 rows and 4 columns of integers.
Initialization: 2D arrays can be initialized during declaration by providing values within curly braces, nested to represent rows and columns.

    int data[2][3] = {{1, 2, 3}, {4, 5, 6}}; // Initializes a 2x3 array.
Accessing Elements: Individual elements are accessed using two indices: the first for the row and the second for the column. Both indices are zero-based.


    int value = matrix[0][2]; // Accesses the element in the first row (index 0) and third column (index 2).
Traversal: Nested loops are typically used to iterate through all elements of a 2D array, with an outer loop for rows and an inner loop for columns.

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            // Process matrix[i][j]
        }
    }
Memory Representation: While conceptually a grid, 2D arrays are stored contiguously in memory in a row-major order 
(all elements of the first row, then all elements of the second row, and so on).
Common uses of 2D arrays:
Representing matrices in mathematical operations.
Storing data in tables or grids, such as game boards, image pixels, or spreadsheet data.
Implementing relational database-like structures.



 // -----------------  How to store data in memory -----------------

  Storing data in memory, particularly Random Access Memory (RAM), involves several mechanisms depending on the context and programming language.
1. Variable Declaration and Assignment:
In most programming languages, declaring a variable and assigning a value to it directly stores that value in a designated memory location. 
  For example, in C or Python:
int myInteger = 10; // Stores the integer 10 in memory, associated with 'myInteger'
my_string = "Hello" # Stores the string "Hello" in memory, associated with 'my_string'
The compiler and operating system manage the exact memory address allocation.
  
2. Data Structures:

Complex data can be organized and stored in memory using various data structures.
Arrays:
Store collections of similar data types in contiguous memory blocks.
  
Lists/Vectors:
Dynamic arrays that can grow or shrink, often implemented with underlying arrays.
  
Objects/Structs:
Group related data items (variables) together into a single unit in memory.
  
Trees/Graphs:
Store data with hierarchical or networked relationships using pointers or references to link nodes in memory.
  
Hash Tables/Dictionaries:
Store key-value pairs, using a hash function to map keys to memory locations for efficient retrieval.
  
3. Dynamic Memory Allocation:
For data whose size or lifespan is not known at compile time, dynamic memory allocation allows programs to request memory during runtime.
malloc/free (C/C++): Functions to allocate and deallocate blocks of memory from the heap.
new/delete (C++): Operators for object-oriented memory management.
Garbage Collection (Java, Python, C#): Automatic memory management systems that reclaim unused memory.

4. Caching:
In-memory caches are used to store frequently accessed data for faster retrieval, reducing the need to access slower storage like disk drives. This involves placing copies of data in a faster memory tier (like RAM) closer to the CPU.

5. In-Memory Databases:
These databases store entire datasets or significant portions of them directly in RAM, enabling extremely fast data processing and analytics compared to disk-based databases.
  

✅ Memory Layout
Stored in row-major order (row by row).
arr[i][j] address = base + (i * colCount + j) * sizeof(datatype)

✅ Common Patterns
Row-wise traversal
for(int i=0;i<rows;i++){
   for(int j=0;j<cols;j++)
      cout<<arr[i][j]<<" ";
}


Column-wise traversal
for(int j=0;j<cols;j++){
   for(int i=0;i<rows;i++)
      cout<<arr[i][j]<<" ";
}


Diagonal (square matrix)
for(int i=0;i<n;i++)
    cout << arr[i][i] << " ";   // main diagonal
for(int i=0;i<n;i++)
    cout << arr[i][n-i-1] << " "; // secondary diagonal

✅ Passing to Functions
void print(int arr[][3], int rows) {   // second dim needed
    for(int i=0;i<rows;i++)
        for(int j=0;j<3;j++)
            cout<<arr[i][j]<<" ";
}

✅ Dynamic 2D Arrays
Using pointers
int** arr = new int*[rows];
for(int i=0; i<rows; i++)
    arr[i] = new int[cols];


Using vector
vector<vector<int>> arr(rows, vector<int>(cols, 0));

✅ Common Interview Qs
Matrix transpose
Rotate matrix 90°
Search in sorted 2D array
Spiral print of matrix
Sum of rows/cols/diagonals
Max/min in 2D array


✅ Quick Tips

2D array = contiguous block in memory.
Always fix second dimension when passing to a function.
Prefer vector<vector<int>> in modern C++ for flexibility.


  📌 1. Matrix Transpose
Swap rows ↔ columns (for square matrix).

void transpose(int arr[][3], int n) {
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

📌 2. Rotate Matrix 90° (Clockwise)
👉 Trick: Transpose → Reverse each row.

void rotate90(int arr[][3], int n) {
    // transpose
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) swap(arr[i][j], arr[j][i]);
    }
    // reverse each row
    for(int i=0;i<n;i++) {
        reverse(arr[i], arr[i]+n);
    }
}

📌 3. Search in Sorted 2D Array
(Matrix sorted row-wise & col-wise)

bool searchMatrix(int arr[][4], int rows, int cols, int target) {
    int i=0, j=cols-1; // start at top-right
    while(i<rows && j>=0) {
        if(arr[i][j]==target) return true;
        else if(arr[i][j]>target) j--;
        else i++;
    }
    return false;
}

📌 4. Spiral Print of Matrix
👉 Traverse layer by layer.

void spiralPrint(int arr[][4], int rows, int cols) {
    int top=0, bottom=rows-1, left=0, right=cols-1;

    while(top<=bottom && left<=right) {
        for(int i=left;i<=right;i++) cout<<arr[top][i]<<" ";
        top++;
        for(int i=top;i<=bottom;i++) cout<<arr[i][right]<<" ";
        right--;
        if(top<=bottom) {
            for(int i=right;i>=left;i--) cout<<arr[bottom][i]<<" ";
            bottom--;
        }
        if(left<=right) {
            for(int i=bottom;i>=top;i--) cout<<arr[i][left]<<" ";
            left++;
        }
    }
}

📌 5. Sum of Rows / Columns / Diagonals
void rowColSum(int arr[][3], int n) {
    // Row sums
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=0;j<n;j++) sum+=arr[i][j];
        cout<<"Row "<<i<<" sum = "<<sum<<endl;
    }

    // Col sums
    for(int j=0;j<n;j++) {
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i][j];
        cout<<"Col "<<j<<" sum = "<<sum<<endl;
    }

    // Diagonals
    int d1=0,d2=0;
    for(int i=0;i<n;i++) {
        d1+=arr[i][i];           // main diagonal
        d2+=arr[i][n-i-1];       // secondary diagonal
    }
    cout<<"Main diag sum = "<<d1<<endl;
    cout<<"Sec diag sum = "<<d2<<endl;
}

📌 6. Max / Min in 2D Array
void findMaxMin(int arr[][3], int rows, int cols) {
    int mx=INT_MIN, mn=INT_MAX;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            mx=max(mx, arr[i][j]);
            mn=min(mn, arr[i][j]);
        }
    }
    cout<<"Max = "<<mx<<", Min = "<<mn<<endl;
}


✅ With these 6 patterns you can crack 90% of 2D array interview questions.
Transpose + Rotate → manipulation
Search → optimized traversal
Spiral → traversal technique
Sum → accumulation
Max/Min → scanning
  
