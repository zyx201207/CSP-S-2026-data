#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,n;
	cin>>a>>b>>c>>d;
	if(d[2]<b[2])
	{
		n[0]=b[2];
		b[2]=d[2];
		d[2]=n[0];
	}
	if(a!=c)cout<<"0000";
	else{
		cout<<"1";
		if(b[0]!=d[0]||b[1]!=d[1])
			cout<<"000";
		else{
			cout<<"1";
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F'))
				cout<<"00";
			else{
				cout<<"1";
				if(b[2]=='A'&&d[2]=='B'||b[2]=='C'&&d[2]=='C'||b[2]=='D'&&d[2]=='F')
				cout<<"1";
				else cout<<"0";
			} 
		}
	}
	return 0;
}
