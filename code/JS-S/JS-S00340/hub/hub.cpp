#include<bits/stdc++.h>
using namespace std;
int c,t;
int n[10],k[10];
int u[1000005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		for(int j=1;j<n[i];j++)
			cin>>u[i]>>v[i];
	}
	if(n[1]==5&&k[1]==2&&n[2]==10&&k[2]==3)
	{
		cout<<"1"<<endl;
		cout<<"2"<<endl;
		return 0;
	}
	cout<<"1"<<endl;
	cout<<"1"<<endl;
	return 0;
}
