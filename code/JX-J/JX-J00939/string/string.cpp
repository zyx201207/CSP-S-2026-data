#include<bits/stdc++.h>
using namespace std;
int a[10000000];
char b[10000000];
string s;
long long c=0;
bool q=1;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    int d=a[i];

    while(d--){s=s+b[i];}

    if(b[i]!=b[i-1]&&i!=1)q=0;
}
int f=s.size();
for(int i=1;i<=f/2;i++)
    if(s[i]!=s[f-i+1])c++;
if(q==1)cout<<"0";
else cout<<c;
return 0;
}
