#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n,m,a[500005],ans[300005],last[300005],last2[300005];
set<int>f[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(last[a[i]]!=i)last2[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(i==last[a[i]]){
			int j=i+1;
			if(j!=last[a[j]]){
				j=last[a[j]];
			} 
			f[a[i]]=f[a[j]]; 
			f[a[i]].insert(a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j:f[a[i]]){
			ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

