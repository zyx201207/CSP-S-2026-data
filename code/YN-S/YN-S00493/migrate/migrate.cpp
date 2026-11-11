#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6;
int x[N],C,T,n,d,ans;
map<pair<int,int>,int>mp,minn;
map<int,int>vis;
void dfs(int dep,int st,int sp,int now){
	if(now==sp){
		if(!mp.count(make_pair(st,sp))){
			mp[make_pair(st,sp)]++;
			minn[make_pair(st,sp)]=dep;
		}else if(dep<=minn[make_pair(st,sp)]){
			mp[make_pair(st,sp)]++;
		}
	}else{
		for(int i=d;i>=1;i--){
			if(now+i<=sp&&vis.count(now+i)) dfs(dep+1,st,sp,now+i);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	do{
		ans=0;
		mp.clear();
		cin>>n>>d;
		int pl=0;
		for(int i=1;i<=n;i++){
			/**/
			int ind;
			cin>>ind;
			if(ind<0&&i==1) pl=0-ind;
			x[i]=ind+pl+1;
			vis[x[i]]=1;
			
			//cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(0,x[i],x[j],x[i]);
			}
		}
		
		for(auto it=mp.begin();it!=mp.end();it++){
			if(it->second==2) ans++;
			//cout<<it->first.first<<'-'<<it->first.second<<' '<<it->second<<"\n";
		}
		cout<<ans<<"\n";
		//cout<<"\n";
	}while(--T);
	return 0;
}
