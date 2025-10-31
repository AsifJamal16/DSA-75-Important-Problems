//Rotate an array by k positions.

#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>&vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}
vector<int> rotateVector(vector<int>nums,int k){
    int k_res=k%nums.size();
    if(k_res==0){
        return nums;
    }
    vector<int>res;
    for(int i=k_res;i<nums.size();i++){
        res.push_back(nums[i]);
    }
    for(int i=0;i<k_res;i++){
        res.push_back(nums[i]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>rotate=rotateVector(v,k);
    print(rotate);
    return 0;
}

