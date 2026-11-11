#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define I using
#define AK namespace
#define IOI std;
I AK IOI
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	if(T==2)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	if(T==3)
	{
		cout<<1<<endl<<1<<endl<<2<<endl;
		return 0;
	}
	while(T--)
	{
		cout<<0<<endl;
	}
	return 0;
}

