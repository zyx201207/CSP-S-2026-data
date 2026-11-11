#include<bits/stdc++.h>
using namespace std;
char a[3],b[3],ca[2],cb[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca[0]>>ca[1]>>a[0]>>a[1]>>a[2]>>cb[0]>>cb[1]>>b[0]>>b[1]>>b[2];
	if(ca[0]==cb[0]&&ca[1]==cb[1]) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(a[2]<='C'&&b[2]<='C')
	{
		if(abs((int)a[2]-b[2])==1) cout<<11;
		else cout<<10;
	}
	else if(a[2]>='D'&&b[2]>='D')
	{
		cout<<11;
	}
	else cout<<"00";
	return 0;
}

