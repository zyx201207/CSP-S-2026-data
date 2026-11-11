#include<bits/stdc++.h>
using namespace std;
int cc,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>cc>>t;
	for(int i=1;i<=n;i++)
	{
		if(i==2)cout<<i-1<<endl;
		else if(i%3==0||i%4==0)cout<<i<<endl;
		else if(i==6||i==9)cout<<1<<endl;
		else cout<<i+1<<endl;
	}
	return 0;
}