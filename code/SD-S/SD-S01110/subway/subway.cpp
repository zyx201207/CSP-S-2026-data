#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#define int long long
using namespace std;
int c;
int n;
int m;
int d;
int qq;
int a[1000005];
int as[5000005];
map <int , int > mp1;
map <int , int > mp2;
struct qu{
	int s;
	int e;
	int as;
	int idx;
}qr[200005];
struct no{
	int v;
	int w;
};
vector <no > g[5000005];
struct eg{
	int v;
	int as;
	bool operator <(const eg & b) const{
		return v < b.v;
	}
};
priority_queue <eg > q;
bool cmp(qu a , qu b){
	return a.s < b.s;
}
bool cmp2(qu a , qu b){
	return a.idx < b.idx;
}
void dij(int s){
	q.push({s , 0});
	while(!q.empty()){
		eg t = q.top();
		q.pop();
		if(t.as >= as[t.v]){
			continue;
		}
		as[t.v] = t.as;
		for(auto j : g[t.v]){
			q.push({j.v , j.w + t.as});
		}
	}
}
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i = 1;i <= m;i++){
		cin>>a[i];
		g[i + n].push_back({i + n + m , a[i]});
		g[i + n + m].push_back({i + n , a[i]});
	}
	if(n == 1){
		for(int i = 1;i <= n;i++){
			int k;
			cin>>k;
			for(int j = 1;j <= k;j++){
				int v;
				int t;
				cin>>v>>t;
				mp1[v] = t;
			}
		}
		while(qq--){
			int x;
			int y;
			cin>>x>>y;
			cout<<a[x] + mp1[x] + mp1[y] + a[y]<<"\n";
		}
		return 0;
	}else if(n == 2){
		for(int i = 1;i <= n;i++){
			int k;
			cin>>k;
			for(int j = 1;j <= k;j++){
				int v;
				int t;
				cin>>v>>t;
				if(i == 1){
					mp1[v] = t;
				}else if(i == 2){
					mp2[v] = t;
				}
			}
		}
		int minn = 1e18;
		for(int i = 1;i <= m;i++){
			if(mp1[i] != 0 && mp2[i] != 0){
				minn = min(minn , mp1[i] + mp2[i]);
			}
		}
		while(qq--){
			int x;
			int y;
			cin>>x>>y;
			if((mp1[x] != 0 && mp1[y] != 0) || (mp2[x] != 0 && mp2[y] != 0)){
				if((mp1[x] != 0 && mp1[y] != 0) && (mp2[x] != 0 && mp2[y] != 0)){
					cout<<a[x] + a[y] + min(mp1[x] + mp1[y] , mp2[x] + mp2[y])<<"\n";
				}else if(mp1[x] != 0 && mp1[y] != 0){
					cout<<a[x] + a[y] + mp1[x] + mp1[y]<<"\n";
				}else{
					cout<<a[x] + a[y] + mp2[x] + mp2[y]<<"\n";
				}
			}else{
				if(mp1[x] != 0 && mp2[y] != 0){
					cout<<a[x] + a[y] + minn + mp1[x] + mp2[y]<<"\n";
				}else{
					cout<<a[x] + a[y] + minn + mp2[x] + mp1[y]<<"\n";
				}
			}
		}
		return 0;
	}else{
		for(int i = 1;i <= n;i++){
			int k;
			cin>>k;
			for(int j = 1;j <= k;j++){
				int v;
				int t;
				cin>>v>>t;
				g[i].push_back({v + n , t});
				g[v + n].push_back({i , t});
			}
		}
		for(int i = 1;i <= qq;i++){
			int x;
			int y;
			cin>>x>>y;
			qr[i].s = x;
			qr[i].e = y;
			qr[i].idx = i;
		}
		sort(qr + 1 , qr + 1 + qq , cmp);
		int idx = 1;
		while(idx <= qq){
			for(int i = 1;i <= n + m + m;i++){
				as[i] = 0x3f3f3f3f3f3f3f3f;
			}
			dij(qr[idx].s + n + m);
			int now = qr[idx].s;
			while(qr[idx].s == now && idx <= qq){
				qr[idx].as = as[qr[idx].e + n + m];
				idx += 1;
			}
		}
		sort(qr + 1 , qr + 1 + qq , cmp2);
		for(int i = 1;i <= qq;i++){
			cout<<qr[i].as<<"\n";
		}
	}	
	return 0;
}
