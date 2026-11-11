#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
bool bit[200005][32];
int cnt[32];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> g;
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		for(int j=0;(1ll<<j)<x;++j){
			if(x&(1ll<<j)){
				bit[i][j]=1;
				++cnt[j];
			}
		}
		g.push_back(i);
	}	
	for(int i=30;i>=0;--i){
		vector<int> ng;
		if(cnt[i]>=m){
			for(int x:g){
				if(bit[x][i]) ng.push_back(x);
			}
			if(ng.size()>=m){
				ans+=(1ll<<i);
				g=ng;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/