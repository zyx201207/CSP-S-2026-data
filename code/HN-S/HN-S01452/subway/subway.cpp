#include<bits/stdc++.h>
#define icezuikeai return 0;
#define int long long
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],x,y,a[505][50005],t[505][50005],sum,minn;
bool p[505];
vector<vector<int> >st(500005);
void dfs(int xian){
	bool find=0;
	for(int i=1;i<=k[xian];i++){
		if(a[xian][i]==y){
			sum+=(t[xian][y]);
			find=1;
			break;
		}
	}
	if(find==1){
		minn=min(minn,sum);
		return ;
	}
	for(int i=1;i<=k[xian];i++){//这条线上的第i个车站 
	    int zhan=a[xian][i]; 
	    for(int j=0;j<st[zhan].size();j++){//第j条线 
	        int huan=st[zhan][j];
	   	    if(p[huan]==0&&huan!=xian){
	   	    	p[huan]=1;
	   	    	int now=sum;
	   	    	sum+=(t[xian][zhan]+t[huan][zhan]);
	   	    	dfs(huan);
	   	    	sum=now;
	   	    	p[huan]=0;
			}
	    }
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
		    int cc;
			cin>>a[i][j]>>cc;
			t[i][a[i][j]]=cc;
			st[a[i][j]].push_back(i);
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=1314520;
		for(int i=0;i<st[x].size();i++){
			minn=1314520;
			sum=0;
			memset(p,0,sizeof(p));
			dfs(st[x][i]);
			minn+=t[st[x][i]][x];
			ans=min(ans,minn);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	icezuikeai
}
