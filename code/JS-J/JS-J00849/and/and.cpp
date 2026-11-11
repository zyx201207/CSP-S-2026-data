#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH
void FREOPEN(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
namespace{
constexpr int N=200005;
int v[N];
void solve(){
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(v[j]&(1<<i))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!(v[j]&(1<<i)))v[j]=0;
			}
		}
	}
	cout<<ans;
}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
	FREOPEN("and");
#elif defined(HAND_PATH)
	string path;
	cin>>path;
	FREOPEN(path);
#endif
	solve();
	return 0;
}
