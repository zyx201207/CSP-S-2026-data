#include<bits/stdc++.h>
using namespace std;
int main()
{
//freopen("string.in","r",stdin);

//freopen("string.out","w",stdout);
int n,m,cnt=0;
string a="",b,c="";
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>m;
	cin>>b;
	for(int i=1;i<=m;i++)
	{
		a+=b;
	}
	
}
for(int i=a.size();i>=1;i--)
{
	c+=a[i];
}
if((c==a)||(n==1))
{
	cout<<0;
	return 0;
}
for(int i=1;i<=a.size();i++)
{
	if(c[i]!=a[i])
	{
		cnt++;
	}
	
}
cout<<cnt;










//cout<<0;
return 0;

}
