#include<bits/stdc++.h>
using namespace std;
string a,b;
char c[1000005],d[1000005];
long long int i,n,m,s;
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	if(a==b)
		cout<<'1';
		else
		cout<<'0';
		
	if(c[1]==d[1]&&c[0]==d[0]&&a==b)
	cout<<'1';
	else
	cout<<'0';
	
	if(c[1]==d[1]&&c[0]==d[0]&&a==b&&c[2]<='C'&&d[2]<='C'||c[2]>='D'&&d[2]>='D')
	cout<<'1';
	else
	cout<<'0';
	
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&c[2]-1==d[2]&&c[2]!='D'||d[2]-1==c[2]&&d[2]!='D')
	cout<<'1';
	else
	cout<<'0';
	
	return 0;

}