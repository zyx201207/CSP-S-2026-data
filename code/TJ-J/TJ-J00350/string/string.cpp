#include<iostream>
#include<string>
using namespace std;
const int N=2e5+10;
int n,b;
int a[N];
char c[N];
int su=0;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		b+=a[i];
		for(int j=0;j<a[i];j++)
			s+=c[i];
	}
	for(int i=0;i<b;i++)
	{
		if(s[i]!=s[b-i-1])
		{
			su++;
		}
	}
	cout<<su/2;
	return 0;	
}
