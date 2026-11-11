#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+100;
long long a[N],c[N];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,ans=0,cnt=0,s,j=0;

cin>>n>>m;
for(int i=0;i<n;i++)
{
   cin>>a[i];
}
sort(a,a+n);
for(int i=0;i<n-1;i++)
{
   c[i]=a[i+1]-a[i];
}
sort(c,c+n-1);

for(int i=0;i<n-1;i++)
{
ans+=a[i];
    if(a[i]-ans<=m)
    {
        cnt++;

        s=a[i]+ans;
        j=i;

    }
}

for(int i=j+1;i<n;i++)
{
    if(a[i]==s)
    {
        cnt++;
    }
}

cout<<cnt<<endl;
return 0;
}
