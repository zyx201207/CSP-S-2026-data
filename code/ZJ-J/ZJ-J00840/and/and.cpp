#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,l,num;
int ans[35];
bool vis[200010];
vector<int> a[200010];
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x){
			a[i].push_back(x%2);
			x/=2;
		}
		x=a[i].size();
		l=max(l,x);
	}
	for(int i=1;i<=n;i++){
		if(a[i].size()<l){
			for(int j=a[i].size()+1;j<=l;j++) a[i].push_back(0);
		}
	}
	for(int j=l-1;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i][j]) cnt++;
		}
		if(cnt>=m){
			ans[j]=1;
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(!a[i][j]) vis[i]=1;
			}
		}
		else ans[j]=0;
	}
	int x=1;
	for(int i=0;i<l;i++){
		num+=x*ans[i];
		x=x*2;
	}
	cout<<num;
	return 0;
}
