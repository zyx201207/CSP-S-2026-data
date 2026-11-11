#include<bits/stdc++.h>
using namespace std;
int a,b;long long c,d,k[2000010],o[100000];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>c>>d;
		cout<<c/(d+1)<<"\n";
		for(int j=1;j<c;j++)cin>>k[i]>>o[i];
	}
	return 0;
}