#include <iostream>
#include <vector>
using namespace std; 

int findLargest(const vector<int>& nums) {

    int largest = nums[0];

    for (int num : nums){

        if (num > largest) {
            largest = num;
        }
    }

    return largest;

}

void reverseVector(vector<int>& nums){

    if (nums.empty()) {
        return;
    }

    int left = 0;
    int right = nums.size()-1;

    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }

}

int sumVector(const vector<int>& nums){

    int sum = 0;

    for (const int& num : nums){
        sum += num;
    }

    return sum;
}

void removeEven(vector<int>& nums){

    int size = nums.size();

    for(int i = 0; i < size; i++){

        if (nums[i] % 2 == 0){
            nums.erase(nums.begin() + i);
            size--;
            i--;
        }
    }
}

int main() {

    // vector<int> v = {1, 2, 3, 10, 8, 5};

    // int result = findLargest(v);

    // cout << "Largest : " << result << '\n';

    //+--------------------+ reverse

    // vector<int> v = {2, 3, 4, 5};

    // reverseVector(v);

    // for (int num : v)
    // {
    //     cout << num << " ";
    // }

    // cout << '\n';

    //+-----------------------+ sum

    // vector<int> v = {1, 2, 3, 4, 5};
    // int result = sumVector(v);
    // cout << "Sum : " << result << '\n';

    //+------------------------+ even erase

    //+--------------------+ reverse

    vector<int> v = {1, 2, 3, 4, 5};

    removeEven(v);

    for (int num : v)
    {
        cout << num << " ";
    }

    cout << '\n';


    return 0;
}