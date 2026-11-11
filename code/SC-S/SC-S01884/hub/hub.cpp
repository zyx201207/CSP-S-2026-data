#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(n/2<k+1&&k!=n)cout<<1<<endl;
		else cout<<(n/2)/(k+1)<<endl;
	}
	return 0;
}