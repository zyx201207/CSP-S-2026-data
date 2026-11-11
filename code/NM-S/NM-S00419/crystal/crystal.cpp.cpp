#include<bits/stdc++.h>
using namespace std;
int main(){

freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,num;
cin>>n>>num;
vector<int> v8;
for(int i=0;i<n;i++){
    int t;
    cin>>t;
    v8.push_back(t);
}
sort(v8.begin(),v8.end());
int k=0;
while(num||k!=v8.size()){
    if(v8[k]==v8[k+1]){
        k++;
    }else{
    v8[k]++;
    num--;}
}
int sum=1;
for(int i=0;i<v8.size();i++){
    if(v8[i+1]==v8[i])sum++;
}
cout<<sum;
return 0;
}
