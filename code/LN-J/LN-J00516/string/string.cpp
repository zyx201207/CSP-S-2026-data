#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a,ans=0;
char c;
cin>>n;
string s="";
for(int i=0;i<=n-1;i++)
    {
    cin>>a>>c;
    for(int j=0;j<=a-1;j++)
        s+=c;
    }
if(n==1)
    {
    cout<<0;
    return 0;
    }
int q=0,w=(s.size()+1)/2;
while(q<w)
    {
    if(s[q]!=s[w])
        ans++;
    q++,w--;
    }
cout<<ans;
return 0;
}
