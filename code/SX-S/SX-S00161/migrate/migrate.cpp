#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int e[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	while(--m)
	{
		int q,w;
		cin>>q>>w;
		for(int i=1;i<=q;i++)
		{
			cin>>e[i];
		}
		int num=w/(e[q]-e[q-1]);
		if(num==1)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<(q-num-1)*(q-num)/2<<endl;
		}
	}
	return 0;
}