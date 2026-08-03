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

int secondLargest(vector<int>& nums){

    if (nums.size() < 2) return -1;
    int largest = nums[0];
    bool secondLargebool = false;
    int secondLarge;

    if (largest != nums[1]){
        if (nums[1] > largest){
            secondLarge = largest;
            largest = nums[1];
        } else {
        secondLarge = nums[1];
        }

        secondLargebool = true;
    }

    for (int i = 2; i < nums.size(); i++){

        if (secondLargebool){
            if (nums[i] > largest){
                secondLarge = largest;
                largest = nums[i];                
            }
            else if (nums[i] > secondLarge && nums[i] != largest){
                secondLarge = nums[i];
            }
            
        } else {
            if (nums[i] != largest){
                if (nums[i] > largest){
                    secondLarge = largest;
                    largest = nums[i];
                } else {
                secondLarge = nums[i];
                }
                secondLargebool = true;
            }
        }

    }

    if (!secondLargebool) return -1;

    return secondLarge;
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

    // vector<int> v = {1, 2, 3, 4, 5};

    // removeEven(v);

    // for (int num : v)
    // {
    //     cout << num << " ";
    // }

    // cout << '\n';
    
    //+---------------------------+ secondlarge 

    vector<int> v = {1, 2, 3, 10, 8, 5};

    int result = secondLargest(v);

    cout << "SecondLarge : " << result << '\n';

    return 0;
}