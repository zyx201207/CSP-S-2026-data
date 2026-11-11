#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=0;
vector<int> b[35],e(N);
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	if(m==1){
		for(int i=2;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans;
		return 0;
	}if(m==n){
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}cout<<ans;
		return 0;
	}
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
			if(a[i]&(1<<j)){
				b[j].push_back(i);
			}
		}
	}
	for(int i=29;i>=0;i--){
		int cnt=0;
		if(b[i].size()<m)continue;
		vector<int> g(1,i);
		for(int j=i-1;j>=0;j--){
			e.assign(n+5,0);
			if(b[j].size()<m)continue;
			for(int k=0;k<b[j].size();k++){
				e[b[j][k]]++;
			}int sum=0;
			for(int k=0;k<b[i].size();k++){
				if(e[b[i][k]])sum++;
			}if(sum>=m){
				g.push_back(j);
			}
		}for(int j=0;j<g.size();j++){
			cnt+=(1<<g[j]);
		}ans=max(ans,cnt);
	}cout<<ans;
	return 0;
}
