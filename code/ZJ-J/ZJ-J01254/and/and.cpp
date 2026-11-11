#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,ans;
int cnt[114];
vector<int>f[1145];
vector<int>now[51];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=29;j>=0;j--){
			int t=(bool)(x&(1ll<<j));
			if(t) f[j].push_back(i),cnt[j]++;
		}
		now[30].push_back(i);
	}
	for(int i=29,lst=30;i>=0;i--){
		if(cnt[i]<m) continue;
		for(int j=0,k=0;j<f[i].size();j++){
			while(now[lst][k]<f[i][j] and k<now[lst].size()) k++;
			if(k==now[lst].size()) break;
			if(now[lst][k]==f[i][j]) now[i].push_back(now[lst][k]);
		}
		if(now[i].size()>=m) ans+=(1ll<<i),lst=i;
	}
	cout<<ans;
	return 0;
}
