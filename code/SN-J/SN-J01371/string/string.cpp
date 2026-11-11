#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int m;
char g;
int ans=0;
int sum=0;
int f;
int a[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>m>>g;
	for(int j=ans;j<ans+m;j++)
	{
		a[j]=g;
	}
	ans+=m;
}
	
ans-=1;
 f=ans;
if(ans%2==0)
{
	ans/=2;
}
else
{
	ans+=1;
	ans/=2;
}
for(int i=0;i<=ans;i++)
{
	if(a[i]!=a[f--])
	{
		sum++;
	}
}
cout<<sum;
}
