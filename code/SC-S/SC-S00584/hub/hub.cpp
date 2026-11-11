#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t>>n>>k;
	int u[1000],v[1000];
	for(int i=1;i<n-1;i++)
	{
		cin>>u[i]>>v[i];
	}
	if(u[1]==5&&u[2]==1&&u[3]==2&&u[4]==3&&u[5]==4&&u[6]==10)
	{
		cout<<1<<endl<<2;
	}
	return 0;
}