#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
string s="";
int f(string s){
    long long l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
        sum++;
        }
        l++;
        r--;
    }
    return sum;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>m;
    string x;
    cin>>x;
    for(int j=1;j<=m;j++){
    s+=x;
    }
}
f(s);
cout<<sum;
return 0;
}
