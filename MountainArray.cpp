class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3)
            return false;

        int max = arr[0], maxindex = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > max) {
                maxindex = i;
                max = arr[i];
            }
        }
        
        if(maxindex == arr.size()-1 || maxindex == 0)
            return false;

        return StrictlyDecreasing(maxindex, arr) && StrictlyIncreasing(maxindex, arr);

    }

    bool StrictlyDecreasing(int j, vector<int> arr) {

        for(int i = j; i >= 1; i--) {
            if(arr[i-1] >= arr[i])
                return false;
        }

        return true;
    }

    bool StrictlyIncreasing(int j, vector<int> arr) {

        for(int i = j; i < arr.size()-1; i++) {
            if(arr[i] <= arr[i+1])
                return false;
        }

        return true;
    }
};