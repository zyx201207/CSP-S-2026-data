#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
	int c=0;
	if(a!=b)
	{
		c=1;
		cout<<"0";
	}
	if(c==0)cout<<"1";
	int e=(aa[0]-'0')*10+(aa[1]-'0');
	int d=(bb[0]-'0')*10+(bb[1]-'0');
	if(c==0&&e!=d)
	{
		c=1;
	}
	if(c==1)cout<<"0";
	else cout<<"1";
	if(c==0&&!((aa[2]>='D'&&bb[2]>='D')||(aa[2]<='C'&&bb[2]<='C')))
	{
		c=1;
	}
	if(c==1)cout<<"0";
	else cout<<"1";
	if(c==0&&abs(aa[2]-bb[2])>1)
	{
		c=1;
	}
	if(c==1)cout<<"0";
	else cout<<"1";
	return 0;
}

