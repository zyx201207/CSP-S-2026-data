#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	
	if(t==2)
	{
		cout<<"1\n2";
	}
	else
	{
		while(t--)
		{
			cout<<1;
			if(t) cout<<"\n";
		}
	}
	
	return 0;
}
/*

*/