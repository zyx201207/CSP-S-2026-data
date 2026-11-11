#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pait pair<int,int>
const int N = 5e5+7;
const int M = 21;
const int px = 131;
const int mod = 998244353;
const int Mod = 1e9+7;
int n,m,a[N],pre[N];
int dengcha(int x){
	return (x + 1) * x / 2;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	int maxx = 0; a[0] = -1e18;
	for(int i=1;i<=n;++i){
		int sum = 0;
		for(int j=i+1;j<=n+1;++j){
			sum += a[i] - a[j];
			if(sum > m){
				maxx = max(maxx,j-i);
				break;
			} 
		}
	}
	cout<<maxx<<endl;
	return 0;
}
/* 
5 8
-3 -1 2 2 7
*/
