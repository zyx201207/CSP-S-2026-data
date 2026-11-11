#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long
#define fi first
#define se second
ll dfs(ll s,ll e){
	return 0;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q,tmp,tmp1,tmp2;cin>>c>>m>>n>>d>>q;
	vector<ll> w(m,0); 
	vector<pair<ll,vector<pair<ll,ll>>>> vec(n+1);
	for(ll i=1;i<=m;i++){
		cin>>tmp;w[i]=tmp; 
	}
	vector<pair<ll,ll>> v;
	for(ll i=1;i<=n;i++){
		cin>>tmp;v.clear();v.push_back({0,0});
		for(ll j=1;j<=tmp;j++){
			cin>>tmp1>>tmp2;
			v.push_back(make_pair(tmp1,tmp2));
		}
		vec[i]=make_pair(tmp,v);
	}
	/*if(0<=c&&c<=10){
		for(ll i_1=1;i_1<=q;i_1++){
			cin>>tmp1>>tmp2;
			cout<<dfs(tmp1,tmp2);
		}
		return 0;
	}*/
	queue<vector<ll>> qu;
	for(ll i_1=1;i_1<=q;i_1++){
		cin>>tmp1>>tmp2;
		vector<vector<ll>> vis_1(m+1,vector<ll>(2,-1));vis_1[tmp1][0]=0;
		vector<vector<ll>> vis_2(m+1,vector<ll>(n+1,-1));
		qu.push({tmp1,0,-1});
		while(!qu.empty()){
			ll nw=qu.front()[0],nwz=qu.front()[1],nwzh=qu.front()[2];
			qu.pop();
			if(nwz==0){
				if(vis_1[nw][1]>vis_1[nw][0]+w[nw]||vis_1[nw][1]==-1){
					vis_1[nw][1]=vis_1[nw][0]+w[nw];
					qu.push({nw,1,-1});
				}
			}
			if(nwz==1){
				for(ll i=1;i<=vec.size()-1;i++){
					for(ll j=1;j<=vec[i].fi;j++){
						if(vec[i].se[j].fi==nw){
							if(vis_2[nw][i]>vis_1[nw][1]+vec[i].se[j].se||vis_2[nw][i]==-1){
								vis_2[nw][1]=vis_1[nw][1]+vec[i].se[j].se;
								qu.push({nw,2,i});
							}
						}
					}
				}
				if(vis_1[nw][0]>vis_1[nw][1]+w[nw]||vis_1[nw][0]==-1){
					vis_1[nw][0]=vis_1[nw][1]+w[nw];
					qu.push({nw,0,-1});
				}
			}
			if(nwz==2){
				for(ll i=1;i<=vec.size()-1;i++){
					bool fg=0;
					for(ll j=1;j<=vec[i].fi;j++){
						if(vec[i].se[j].fi==nw){
							fg=1;
						}
					}
					if(fg){
						for(ll j=1;j<=vec[i].fi;j++){
							if(vec[i].se[j].fi!=nw){
								if(vis_2[vec[i].se[j].fi][i]>vis_2[nw][i]||vis_2[vec[i].se[j].fi][i]==-1){
									vis_2[vec[i].se[j].fi][1]=vis_2[nw][i];
									qu.push({vec[i].se[j].fi,2,i});
								}
							}
						}
					}
				}
				ll tim=0;
				for(ll i=1;i<=vec.size()-1;i++){
					for(ll j=1;j<=vec[i].fi;j++){
						if(vec[i].se[j].fi==nw){
							tim=vec[i].se[j].se;break;
						}
					}
				}
				if(vis_1[nw][1]>vis_2[nw][nwzh]+tim||vis_1[nw][1]==-1){
					vis_1[nw][1]=vis_2[nw][nwzh]+tim;
					qu.push({nw,1,-1});
				}
			}
		}
		cout<<vis_1[tmp2][0]<<'\n';
	}
	return 0;
}//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2   32 17
