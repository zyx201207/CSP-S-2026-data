#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int w[50];
int cn[35][35];
vector<int> x;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=-1;
	for(int i=1;i<=n;i++){
		x.clear();
		int cnt=0;
		while(a[i]){
			if(a[i]%2){
				w[cnt]++;
				if(!x.empty()){
					for(int j=0;j<x.size();j++){
						cn[cnt][x[j]]++;
						cn[x[j]][cnt]++;
					}
				}
				x.push_back(cnt); 
				ma=max(ma,cnt);
			}
			cnt++;
			a[i]/=2;
		}
	}
	int ans=0;
	x.clear();
	for(int i=ma;i>=0;i--){
		if(w[i]>=m){
			x.push_back(i);
			ma=i;
			ans+=(1<<i);
			break;
		}
	}
	for(int i=ma-1;i>=0;i--){
		int mi=1e18;
		for(int j=0;j<x.size();j++) mi=min(mi,cn[x[j]][i]);
		if(mi>=m) ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}

