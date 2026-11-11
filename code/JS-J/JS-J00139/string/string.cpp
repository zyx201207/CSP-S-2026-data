#include<bits/stdc++.h>
using namespace std;
string s;
long long ans;
int main(){
freopen("string,in","r",stdin);
freout("string,out","r",stdout);
long long n,l=0;
cin>>n;
for(int i=1;i<=n;i++)
{
    int a;
    char x;
    cin>>a>>x;
    l+=a;
    for(int i=l;i<l-a;l--)
    {
        s[i]=x;
    }
}
for(int i=1;i*2<=l;i++)
{
    if(s[i]!=s[l+1-i])
    {

        ans++;
    }
}
cout<<ans;
return 0;
}
