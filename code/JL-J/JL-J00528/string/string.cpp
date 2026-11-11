#include<bits/stdc++.h>
using namespace std;
long long n,t,k;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
    int x;
    char ch;
    cin>>x>>ch;
    k+=x;
    for(int j=1;j<=x;j++)
    {
        s+=ch;
    }
}
for(int i=0;i<k/2;i++)
{
    if(s[i]!=s[k-i-1])
    {
        t++;
    }
}
cout<<t;
return 0;
}
