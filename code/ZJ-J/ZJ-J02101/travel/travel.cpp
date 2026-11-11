#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		if(d[i]!=b[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if((d[2]-'A'<=2&&b[2]-'A'<=2)||(d[2]-'A'>2&&b[2]-'A'>2)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(d[2]-b[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
