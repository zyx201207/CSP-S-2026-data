#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int c,t,n,k,u[N][3],ans[N];
void dfs(int x,int w)
{
	ans[x]=min(ans[i],w);
	if(u[x][1]) dfs(u[x][1],w+1);
	if(u[x][2]) dfs(u[x][2],w+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	whlie(t--)
	{
		cin>>n>>k;
		if(k==1)
		{
			cout<<n/2;
		}
		else cout<<1;
		cout<<"\n";
	}
	return 0;
}
