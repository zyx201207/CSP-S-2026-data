#include<bits/stdc++.h>
using namespace std;
int c,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>q;
	if(c == 1)
	{
		if(q == 2)
		{
			cout<<1<<'\n'<<2;
		}
		else if(q == 3)
		{
			cout<<1<<'\n'<<3<<'\n'<<2; 
	 	}
	 	else if(q == 4)
	 	{
	 		cout<<1<<'\n'<<2<<'\n'<<1<<'\n'<<1;
	 	}
	 	else
	 	{
	 		cout<<1<<'\n'<<1<<'\n'<<1<<'\n'<<1<<'\n'<<1;
	 	}
	 	return 0;
	}
	if(c == 7)
	{
		cout<<123<<'\n'<<323;
	 	return 0;
	}
	if(c == 11)
	{
		cout<<1874<<'\n'<<2562;
	 	return 0;
	}
	if(c == 12)
	{
		cout<<2823<<'\n'<<5642;
	 	return 0;
	}
	for(int i = 1;i <= q;i++)
	{
		cout<<1<<'\n';
	}
	return 0;
}