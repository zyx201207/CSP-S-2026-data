#include<bits/stdc++.h>
using namespace std;
int n,x,aa;
long l,d;
char as;
vector<char> a(2e9);
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	l=0;
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		cin>>x;cin>>as;
		for(int i=l;i<=l+x;i++)
		{
			a[i]=as;
		}
		l+=x;
	}
	vector<char>::iterator ao=a.begin();
	vector<char>::iterator ap=a.end();
	for(int i=0;i<l/2;i++)
	{
		if(a[i]!=a[l-i])
			d++;	
	}
	cout<<d;
	return 0;
}
