#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t,n[5000],k[5000],u[5000],v[5000];
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>u[j]>>v[j];
		}
		for(int j=1;j<=n[i]-1;j++)
		{
			if(u[j]==v[j]-1)
			{
				if(n[i]==2)
				{
					cout<<"0"<<endl;
					break;
				}
				else
				{
					cout<<"1"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}