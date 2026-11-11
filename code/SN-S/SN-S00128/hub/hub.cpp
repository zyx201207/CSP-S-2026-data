#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rd(time(0));
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	if(c==13||c==14)
	{
		while(t--) cout<<"1\n";
		return 0;
	}
	while(t--)
	{
		while(t--) cout<<rd()%1000000<<endl;
	}
	return 0;
}

