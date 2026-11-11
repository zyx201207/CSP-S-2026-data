#include<bits/stdc++.h>
using namespace std;
long long c,n,m,k,d,q,sa,tt,cur=0,st,ed,ans=-10,sum=0;
long long w[10000010];
long long sj[30][520];
//void dfs(long long st,long long time){
//	if(st==ed){
//		ans=min(time,ans);
//	}
//	else{
//		for(int i=1;i<=n;i++){
//			if(sj[st][i]!=0&&sj[i][st]!=0){
//				cur=i;
//				dfs(cur,sj[st][i]+sj[i][st]);
//			}
//		}
//	}
//}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(sj,0,sizeof(sj));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sa>>tt;
			sj[i][sa]+=tt;
			sum+=tt;
		}
			
	}
	while(q--){
		cin>>st>>ed;
		if(st==ed) cout<<0<<'\n';
		else {
//			dfs(st,0);
			cout<<sum<<'\n';
		}
	}
	return 0;
}