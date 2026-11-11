#include<bits/stdc++.h>
#include<cstdio>
#define int long long
#define endl '\n'
#define Fre
#define Ct

const int N=5e5+10;

using namespace std;

typedef pair<int,int> PII;

int a[N];
int ans[N];
bool f[N];

void solve() {
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>v;
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			for(auto t:v){
				if(t==a[j]){
					while(v.back()!=t) v.pop_back();
					v.pop_back();
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(auto t:v){
			f[t]=1;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=f[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}

signed main() {

#ifdef Fre
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
#endif

#ifdef Ct
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int _=1;
	//cin>>_;
	while(_--) solve();

	return 0;
}

