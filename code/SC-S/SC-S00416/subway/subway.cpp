#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 550;
const int M = 5e5 + 5;
int st[M];
vector<tuple<int,int> >ovr[N];
vector<tuple<int,int> >jl[M];
ll lt[N][N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;++i)cin>>st[i];
	for(int i = 1;i <= m;++i)jl[i].reserve(30);
	for(int i = 1,k;i <= n;++i){
		cin>>k;
		ovr[i].reserve(k + 5);
		for(int j = 1,lj,tim;j <= k;++j){
			cin>>lj>>tim;
			ovr[i].push_back(make_tuple(lj,tim));
			jl[lj].push_back(make_tuple(i,tim));
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			lt[i][j] = (i == j) ? 0 : LONG_MAX;
		}
	}
	for(int i = 1;i <= n;++i){
		for(auto x : ovr[i]){
			int lj = get<0>(x),tim = get<1>(x);
			for(auto h : jl[lj]){
				if(get<0>(h) == i){
					lt[get<0>(h)][i] = lt[i][get<0>(h)] = 0;
					continue;
				}
				lt[get<0>(h)][i] = min(lt[get<0>(h)][i],min(lt[i][get<0>(h)],(ll)tim + (ll)get<1>(h)));
				lt[i][get<0>(h)] = lt[get<0>(h)][i];
			}
		}
	}
	for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				if(i == j)continue;
				lt[i][j] = min(lt[i][k] + lt[k][j],lt[i][j]);
				lt[j][i] = lt[i][j];
			}
		}
	}
	for(int i = 1;i <= q;++i){
		int x,y;
		cin>>x>>y;
		ll ans = LONG_MAX;
		for(auto h : jl[x]){
			for(auto k : jl[y]){
				ans = min(ans,(ll)get<1>(h) + (ll)get<1>(k) + lt[get<0>(h)][get<0>(k)] + (ll)st[x] + (ll)st[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
