#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MAXN=10000000000000000;
ll cc,n,m,dd,q;
ll w[500005];
ll dis[900][900];
vector<ll> vl[1000],valb[500005];
vector<ll> edga[1000],edgb[500005];
struct NODE{
	ll num,dist;
};
bool operator >(NODE x,NODE y){
	return x.dist>y.dist;
}
ll tmpp[600600];
bool vis[600600];
priority_queue<NODE,vector<NODE>,greater<NODE> > que;
void solve(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n+m;j++){
			tmpp[j]=MAXN;
			vis[j]=false;
			que.push((NODE){j,MAXN});
		}
		tmpp[i]=0;
		que.push((NODE){i,0});
		ll cnt=0;
		while(cnt<n+m){
			ll bst=que.top().num;
			ll bstdis=que.top().dist;
			que.pop();
			if(vis[bst])continue;
			vis[bst]=true;
			cnt++;
			tmpp[bst]=bstdis;
			if(bst<=n){
				for(ll j=0;j<edga[bst].size();j++){
					if(!vis[edga[bst][j]+n]){
						if(tmpp[edga[bst][j]+n]>vl[bst][j]+bstdis){
							tmpp[edga[bst][j]+n]=vl[bst][j]+bstdis;
							que.push((NODE){edga[bst][j]+n,tmpp[edga[bst][j]+n]});
						}
					}
				}
			}
			else{
				bst-=n;
				for(ll j=0;j<edgb[bst].size();j++){
					if(!vis[edgb[bst][j]]){
						if(tmpp[edgb[bst][j]]>valb[bst][j]+bstdis){
							tmpp[edgb[bst][j]]=valb[bst][j]+bstdis;
							que.push((NODE){edgb[bst][j],tmpp[edgb[bst][j]]});
						}
					}
				}
			}
		}
		for(ll j=1;j<=n;j++){
			dis[i][j]=tmpp[j];
		}
		while(!que.empty())que.pop();
	}
	
}
void tf(){
	queue<NODE> que1;
	for(int i=1;i<=n;i++){
		for(ll j=1;j<=n+m;j++){
			tmpp[j]=0;
			vis[j]=false;
		}
		que1.push((NODE){i,0});
		vis[i]=true;
		ll cnt=0;
		while(!que1.empty()){
			ll prev=que1.front().num;
			ll prevdis=que1.front().dist;
			que1.pop();
			tmpp[prev]=prevdis;
			if(prev<=n){
				for(int j=0;j<edga[prev].size();j++){
					if(!vis[edga[prev][j]+n]){
						vis[edga[prev][j]+n]=true;
						que1.push((NODE){edga[prev][j]+n,prevdis+1});
					}
				}
			}else{
				prev-=n;
				for(int j=0;j<edgb[prev].size();j++){
					if(!vis[edgb[prev][j]]){
						vis[edgb[prev][j]]=true;
						que1.push((NODE){edgb[prev][j],prevdis+1});
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			dis[i][j]=tmpp[j]*vl[1][0];
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>cc>>n>>m>>dd>>q;
    for(ll i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll xx;
		cin>>xx;
		ll xa,xb;
		for(ll j=1;j<=xx;j++){
			cin>>xa>>xb;
			edga[i].push_back(xa);
			vl[i].push_back(xb);
			edgb[xa].push_back(i);
			valb[xa].push_back(xb);
		}
	}
	if(cc>=16&&cc<=19)tf();
	else solve();
	for(ll i=1;i<=q;i++){
		ll xx,yy,tmp=MAXN;
		cin>>xx>>yy;
		for(ll j=0;j<edgb[xx].size();j++){
			for(ll k=0;k<edgb[yy].size();k++){
				tmp=min(tmp,dis[edgb[xx][j]][edgb[yy][k]]+valb[xx][j]+valb[yy][k]);
			}
		}
		cout<<tmp+w[xx]+w[yy]<<endl;
	}
	return 0;
}

