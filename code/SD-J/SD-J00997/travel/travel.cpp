#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d;
	char ch1,ch2;
	cin>>a>>c>>ch1>>b>>d>>ch2;
	if(!(a==b&&a!=1&&a!=16))
	{
		cout<<"0000";
	}else if(c!=d)
	{
		cout<<"1000";
	}else if((ch1<='C'&&ch2>='D')||(ch2<='C'&&ch1>='D'))
	{
		cout<<"1100";
	}else if(abs(ch1-ch2)==1)
	{
		cout<<"1111";
	}else{
		cout<<"1110";
	}
	return 0;
}

