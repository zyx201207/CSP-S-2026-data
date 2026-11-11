#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	cout<<(a==b);
	cout<<(a==b&&x[0]==y[0]&&x[1]==y[1]);
	cout<<(a==b&&x[0]==y[0]&&x[1]==y[1]&&((x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C')||(x[2]>='D'&&x[2]<='F'&&y[2]>='D'&&y[2]<='F')));
	cout<<(a==b&&x[0]==y[0]&&x[1]==y[1]&&((x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C'&&abs(x[2]-y[2])==1)||(x[2]>='D'&&x[2]<='F'&&y[2]>='D'&&y[2]<='F')));
	return 0;
}

