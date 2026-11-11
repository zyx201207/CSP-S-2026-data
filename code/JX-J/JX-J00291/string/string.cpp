#include<bits/stdc++.h>
using namespace std;
long long n,a;
long long ans=0;
char c;
string s="";
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long i=1;i<=n;i++)
{
    cin>>a>>c;
    for(long long j=1;j<=a;j++)
        s+=c;
}
long long m=s.size();
for(long long i=0;i<m/2;i++)
    if(s[i]!=s[m-1-i])
        ans++;
cout<<ans<<endl;
fclose(stdin);
fclose(stdout);
return 0;
}
