#include<bits/stdc++.h>
using namespace std;
long long z;
string a,b,v,d;
string s,s1;
char c,c1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>v>>d;
	if (a!=v) {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	} 
	cout<<1;
	for (int i=0;i<2;i++) {
		s+=b[i];
		s1+=d[i];
	}
	if (s!=s1) {
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	cout<<1;
	c=b[2];
	c1=d[2];
	if (c1>='A' && c1<='C' && c>='A' && c<='C') {
		cout<<1;
		z++;
		if (c=='A'&&c1=='B' || c=='B'&&c1=='A') {
			cout<<1;
			z++;
		}
		if (c=='C'&&c1=='B' || c=='B'&&c1=='C') {
			cout<<1;
			z++;
		}
	} else if (c1>='D' && c1<='F' && c>='D' && c<='F' && c!='E' && c1 !='E') {
		cout<<11;
		z+=2;
	}
	if (z<2) {
		for (int i=1;i<=2-z;i++) {
			cout<<0;
		}
	}
	
	return 0;
}