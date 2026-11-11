#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
ll c,n,m,d,q,ans;
void dfs(ll start,ll goal,vector<vl> line,vector<vl> t,vl w,vl k,ll time,ll nowline,vector<vl> station){
	if(nowline==-1){
		for(auto &x : station[start]){
			ll fff;
			FOR(i,1,line[x].size()){
				if(line[x][i]==start){
					fff=i;
					break;
				}
			}
			time+=t[x][fff];
			//dengshang x hao xian lieche;
			cout<<"now load on line "<<x<<"\n";
			dfs(start,goal,line,t,w,k,time,x,station);
		}
	}else{
		FOR(j,1,k[nowline]){
			ll fff=0;
			FOR(l,1,line[nowline].size()){
				if(line[nowline][l]==goal){
					fff=1;
					break;
				}
			}
			time+=t[nowline][fff];
			if(fff){
				time+=w[line[nowline][j]];
				ans=min(ans,time);
				return;
			}
			if(station[line[nowline][j]].size()>1){
				//huancheng i hao xian
				for(auto i:station[line[nowline][j]]){
					if(i!=nowline){
						ll fff;
						FOR(l,1,line[nowline].size()){
							if(line[nowline][l]==line[nowline][j]){
								fff=i;
								break;
							}
						}
						dfs(start,goal,line,t,w,k,time+t[line[nowline][j]][fff]+t[i][fff],i,station);
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vl w(m+1),k(n+1);
	FOR(i,1,m){
		cin>>w[i];
	}
	vector<vl> line(n+1,vl(d+1)),t(n+1,vl(d+1)),station(m+1);//i hao xianlu ,d ge zhandian
 	for(ll i=1;i<=n;i++){
		cin>>k[i];//di i tiao you a[i] ge zhan
		FOR(j,1,k[i]){
			cin>>line[i][j]>>t[i][j];
			station[line[i][j]].push_back(i);
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ans=INT_MAX;
		dfs(x,y,line,t,w,k,w[x],-1,station);
		cout<<ans<<"\n";
	}
}
//i am luogu user 1457377
//i am also sc-j00229(bu que ding)
//rp++ ak ioi;
//this afternoon i use linux so there are no chinese
//thanks for looking my code!
//wo shi quan jifang zui hao zhi ren ,only i use linux
//li jie le ,2h dou zai xie zhe ge lei ting da mo ni
//WO YAO ZHA LE ,DIANNAO LANPING 3 CI,XIE BU DONG LE