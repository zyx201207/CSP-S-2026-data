#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],ans[N],v[N],f[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool ff=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) {
			ff=0;
			break;
		}
	}
	if(ff){
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[a[i-1]]=i-1;
			}
		}
		ans[a[n]]=n;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				for(int k=v[a[j]];k<j;k++){
					if(f[k]) continue;
					ans[a[k]]--;
					v[a[k]]=0;
					f[k]=1;
				}
			}
			v[a[j]]=j;
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3

*/
