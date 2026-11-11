#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n;
	cin>>m;
	char x[3],y[3];
	for(int i=1;i<=3;i++)
		cin>>x[i];
	cin>>n;
	for(int j=1;j<=3;j++)
		cin>>y[j];
	if(m!=n)
	{
		cout<<"0000";
		return 0;
	}
	else
		cout<<"1";
	if(x[2]==y[2])
		cout<<1;
	else
		cout<<0;
	if(x[3]=='A'&&y[3]=='B'&&x[2]==y[2]||x[3]=='B'&&y[3]=='A'&&x[2]==y[2]||x[3]=='C'&&y[3]=='A'&&x[2]==y[2]||x[3]=='A'&&y[3]=='C'&&x[2]==y[2]||x[3]=='B'&&y[3]=='C'&&x[2]==y[2]||x[3]=='C'&&y[3]=='B'&&x[2]==y[2]||x[3]=='D'&&y[3]=='F'&&x[2]==y[2]||x[3]=='F'&&y[3]=='D'&&x[2]==y[2])
		cout<<1;
	else
		cout<<0;
	if(int(x[3])==int(y[3]-1)&&x[3]!='C'&&x[3]!='D'&&y[3]!='C'&&y[3]!='D'&&x[2]==y[2])
		cout<<1;
	else
		cout<<0;
	
	return 0;
 } 
