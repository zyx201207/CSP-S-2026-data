#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans;
bool f[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int res=0;
		vector<int>t;
		for(int j=1;j<=n;j++){
			if(f[j]) continue;
			if(a[j]&(1<<i)) res++;
			else t.push_back(j);
		}
		if(res>=m){
			ans+=(1<<i);
			for(int v:t) f[v]=1;
		}
	}
	cout<<ans;
	return 0;
}
/*
By ZJ-J00357.
Luogu UID:1086453.
*/