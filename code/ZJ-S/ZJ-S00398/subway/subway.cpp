#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long c,n,m,d,q;
long long w[500010],k[510];
struct node{long long a,t;};
vector<node>ve[500010];
long long min_len[510][510];
int main(){
	int i,j,l;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++){
			long long a,t;cin>>a>>t;
			ve[a].push_back({i,t});
		}
	}	
	memset(min_len,0x3f,sizeof(min_len));
	for(i=1;i<=n;i++)min_len[i][i]=0;	
	for(i=1;i<=m;i++){
		int len=ve[i].size();
		for(j=0;j<len;j++){
			for(l=j+1;l<len;l++){	
				node py=ve[i][l];node px=ve[i][j];
				min_len[px.a][py.a]=min(min_len[px.a][py.a],px.t+py.t);
				min_len[py.a][px.a]=min(min_len[py.a][px.a],px.t+py.t);
			}
		}
	}
	for(l=1;l<=n;l++){
		for(i=1;i<=n;i++){
			if(l==i)continue;
			for(j=1;j<=n;j++){
				min_len[i][j]=min(min_len[i][j],min_len[i][l]+min_len[l][j]);
			}
		}
	}
	for(i=1;i<=q;i++){
		long long x,y,sum=5e18;cin>>x>>y;
		for(node dx:ve[x]){
			for(node dy:ve[y]){
				if(min_len[dx.a][dy.a]>=inf)continue;
				sum=min(sum,min_len[dx.a][dy.a]+dx.t+dy.t);
			}
		}
		sum+=w[x]+w[y];cout<<sum<<endl;
	}
	return 0;
}

