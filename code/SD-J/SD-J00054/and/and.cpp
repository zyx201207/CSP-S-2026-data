#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,cnt[101];
vector<int> a[40];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[31].push_back(x);
	}
	for(int k=30;k>=0;k--){
		int po=pow(2,k);
		for(int i=0;i<a[k+1].size();i++){
			if(a[k+1][i]&po){
				cnt[k]++;
			}
		}
		if(cnt[k]>=m){
			for(int i=0;i<a[k+1].size();i++){
				if(a[k+1][i]&po){
					a[k].push_back(a[k+1][i]);
				}
			}
			ans+=po;
		}
		else{
			for(int i=0;i<a[k+1].size();i++){
				a[k].push_back(a[k+1][i]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

