//find the kth largest element in the array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int kthLargest(vector<int>&vec,int k){
    sort(vec.begin(),vec.end());
    vector<int>unique;
    for(int i=0;i<vec.size();i++){
        if(i==0 || vec[i]!=vec[i-1]){
            unique.push_back(vec[i]);
        }
    }
    reverse(unique.begin(),unique.end());
    return unique[k-1];
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
    cout<<kthLargest(v,k);
    return 0;
}