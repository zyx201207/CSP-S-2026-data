#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string out","w",stdout);
    bool flag=1;
    long long n,a,sum=1;
    char b;
    string s="";
    cin>>n;
    cin>>a>>b;
    sum=a;
    for(int j=0;j<a;j++){
        s=s+b;
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s=s+b;
        }
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            flag=0;
        }
    }
    if(flag==1){
        cout<<"0";
        return 0;
    }
    string s2="";
    for(int i=0;i<s.size();i++){
        s2=s[i]+s2;
    }
    if(s==s2){
        cout<<"0";
        return 0;
    }
    cout<<sum;
    return 0;
}
