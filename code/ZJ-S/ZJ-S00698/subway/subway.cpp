#include<bits/stdc++.h>
#define N 50005
using namespace std;
typedef long long ll;
ll len[N],w[505][N],tim[505][N],k[505];
ll q[2*N][5];
ll a[505];
ll c,n,m,d,qu,cc;
void bfs(ll s,ll t)
{
	ll tail=1,head=1;
	q[tail][1]=s;
	q[tail][2]=1;
	q[tail][3]=0;
	while(head<=tail){
		if(q[head][2]==1){
			tail++;
			q[tail][1]=1;
			q[tail][2]=2;
			q[tail][3]=head;
		}else{
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<=k[i];j++){
					if(w[i][j]==q[head][1]){
						for(ll f=1;f<=k[i];f++){
							if(w[i][j]==t) {
								cc=tail;
								return;
							}
							tail++;
							q[tail][1]=w[i][j];
							q[tail][2]=2;
							q[tail][3]=head;
						}
						break;
					}
				}
			}
		}
		head++;
	}
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(ll i=1;i<=m;i++)
		cin>>len[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>k[i];
		for(ll j=1;j<=k[i];j++)
			cin>>w[i][j]>>tim[i][j];
	}
	while(qu--)
	{
		ll s,t;
		cin>>s>>t;
		if(s!=t)
		{
			ll ans=0;
			bfs(s,t);
			while(q[cc][3]!=0)
			{
				if(q[cc][2]==1) ans+=len[q[cc][1]];
				else if(q[cc])
				cc=q[cc][3];
			}
			ans+=len[t]+w[t][t];
			cout<<ans<<"\n";
		}
		else cout<<"0\n";
	}
	return 0;
}

