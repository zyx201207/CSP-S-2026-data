#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pii pair<int,int>
#define vec vector
using namespace std;
const int N=2e5+3;

int n, m;
vec<int>a;
void solve(){
	cin >> n >> m;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=0;
	int k;
	vec<int>na;
	for(int j=30;~j;j--){
		bool f=1;
		int nm=0;
		for(int x:a){
			if((x>>j)&1){
				nm++;
				na.push_back(x);	
			}
		}
		if(nm>=m){
			a=na;
			ans+=(1<<j); 
		}
		na.clear();
	}
	cout<<ans;
	
}
signed main(){
	IOS;
	freopen("and.in", "r",stdin);
	freopen("and.out","w",stdout);
    //int t;cin >> t;while(t--)
    solve();
    return 0;
}
