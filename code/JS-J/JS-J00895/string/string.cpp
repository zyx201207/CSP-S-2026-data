#include<bits/stdc++.h>
using namespace std;
string s;
int n,j;
char e;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>j>>e;
        for(int k=0;k<j;k++){
            s+=e;
        }
    }string h=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=h[i])sum++;
    }cout<<sum;
    return 0;}
