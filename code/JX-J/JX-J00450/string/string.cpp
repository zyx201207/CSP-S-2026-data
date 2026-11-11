#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long b[n+5]={};
    string s[n+5]={};
    string as;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>s[i];
        for(int j=1;j<=b[i];j++){
            as+=s[i];
        }
    }
    if(n==1){
       cout<<0;
       return 0;
    }
    long long sum=0;
    for(int i=(as.size()+1)/2,j=(as.size()+1)/2;i>=0,j<=as.size();i--,j++){
        if(i!=j)sum++;
    }
    cout<<sum;
    return 0;
}
