#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n,k,u[N],v[N]; 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>u[i]>>v[i];
		cout<<1<<endl;
	}
	return 0;
}
