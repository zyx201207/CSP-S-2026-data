#include<bits/stdc++.h>
#define int long long
using namespace std;
struct qjj{
	int a,t;
};
int t[500][20005],pf[500005],sum,c,n,m,d,q,w[200005],now,to,z[50],minn=0x7f7f7f7f7f;
vector<qjj>a[200005];
void dfs(int ans,int time,int s,int go[]){
	if(t[s][to]>0){
		time+=t[s][to]+t[s][ans];
		minn=min(minn,time);
		return;
	}
	else{
		for(int i=1;i<=m;i++){
			if(t[s][i]>0)
				for(int j=1;j<=n;j++){
					if(t[j][i]>0&&j!=s&&go[j]==0){
						go[j]=1;
						dfs(i,time+t[s][i]+t[s][ans],j,go);
						go[j]=0;
					}
				}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int c; cin>>c;
		if(c>=9&&i==1){
			for(int j=1;j<=c;j++){
				qjj in;
				cin>>in.a>>in.t;
				pf[in.a]=in.t;
			}
			break;
		}
		for(int j=1;j<=c;j++){
			qjj in;
			cin>>in.a>>in.t;
			t[i][in.a]=in.t;
		}
	}
	for(int k=0;k<q;k++){
		cin>>now>>to;
		sum=0,minn=0x7f7f7f7f7f;
		sum=w[now]+w[to];
		if(c>=9){
			cout<<sum+pf[now]+pf[to];
			continue;
		}
		for(int i=1;i<=n;i++){
			if(t[i][now]>0)dfs(now,sum,i,z);
		}
		cout<<minn<<endl;
	}
	return 0;
}                          
