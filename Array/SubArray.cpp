//Find the sub Array with the given sum
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>&vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}
int vectorSum(vector<int>&vec){
    int sum=0;
    for(int i=0;i<vec.size();i++){
        sum=sum+vec[i];
    }
    return sum;
}
void SubArrayWithGivenSum(vector<int>&vec,int k){
    for(int i=0;i<vec.size();i++){
        vector<int>sub;
        for(int j=i;j<vec.size();j++){
            sub.push_back(vec[j]);
            int sum=vectorSum(sub);
            if(sum==k){
                print(sub);
                cout<<endl;
            }
        }
    }
    return ;
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
    SubArrayWithGivenSum(v,k);
    return 0;
}

