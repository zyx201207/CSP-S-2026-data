#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,cnt;
int a[N];
vector<int>v[65];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v[60].push_back(a[i]);
	}
	for(int i=60;i>=0;i--){
		int ans=0;
		for(int j=0;j<v[i].size();j++){
			if(((v[i][j]>>i)&1)==1){
				ans++;
			}
		}
		if(ans>=m){
			cnt+=(1ll<<i);
			if(i==0)continue;
			for(int j=0;j<v[i].size();j++){
				if(((v[i][j]>>i)&1)==1){
					v[i-1].push_back(v[i][j]);
				}
			}
		}
		else{
			if(i==0)continue;
			for(int j=0;j<v[i].size();j++){
				v[i-1].push_back(v[i][j]);
			}
		}
	}
	cout<<cnt;
	return 0;
}