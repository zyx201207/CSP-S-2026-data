#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll c,n,m,d,q,w[100000],k[10000],a[10000],t[100000],x,y,h,max_;
vector<ll>v[100000];
vector<ll>u[100000];

ll mmxgj(ll x){
	for(ll i=0;i<v[v[x][0]].size();i++){
		if(v[v[x][0]][i]==x)return u[v[x][0]][i];
	}return -1;
}
ll dfs(ll s,ll z,ll _,ll l,ll dfsh,ll _L){
	if(v[_][l]==z)return dfsh+u[_][l];
	for(int i=0;i<v[v[_][l]].size();i++){
		if(_L<=max_){
			dfs(s,z,v[_][l],i,dfsh+u[_][l],_L+1);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(ll i=0;i<m;i++){
		cin>>w[i];
	}
	for(ll i=0;i<n;i++){
		cin>>k[i];
		for(ll j=0;j<k[i];j++){
			cin>>a[j]>>t[j];
			for(int l=0;l<k[i];l++){
				int bj=a[l];
				max_=max(max_,a[l]);
				for(int o=0;o<k[i];o++){
					if(o==l)continue;
					v[bj].push_back(a[o]);
					u[bj].push_back(t[o]);
				}
			}
		}
	}
	for(ll i=0;i<q;i++){
		cin>>x>>y;
		v[0].push_back(x);
		u[0].push_back(mmxgj(x));
		h+=w[x]+w[y];
		ll h1=dfs(x,y,0,0,0,0);
		h+=h1;
		v[0].clear(),u[0].clear();
		cout<<h;
		h=0;
	}
	return 0;
}
