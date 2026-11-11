#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.c.in","r",stdin);
freopen("string.c.out","w",stdout);
int n;
cin>>n;a
string s[n],sam;
long long a[n],san=0,v;
for(int i=0;i<n;i++)
{
	cin>>s[i];
	cin>>a[i];
}
for(int j=0;j<n;j++)
{
	for(int k=0;k<a[j];k++)
	{
		sam=sam+s[k];
	}
}
v=sam.size()/2;
for(int b=0;b<v;b++)
{
	if(sam[b]==sam[n-b])
	{
		san++;
	}
}
cout<<san;
return 0;
}
