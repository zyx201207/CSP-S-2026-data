#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char b[200010];
string s;
long long t=1;
long long ct=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i];j++){
            s+=b[i];
        }
    }
    for(int i=0;i<s.size();i++){
        while(t<=s.size()/2){
        if(s[s.size()-t]!=s[t-1]){
            ct++;
        }
        t++;
        if((s.size()-t!=t-1)||(s.size()-t-t+1!=1)) break;
        }
    }
    cout<<ct;
    return 0;
}
