#include<bits/stdc++.h>
using namespace std;
int n,m,f[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=n;j>=i;j--){
			int maxn=0;
			for(int k=i-1;k<j;k++){
				maxn=max(maxn,f[j]&f[k]);
			}
			f[j]=maxn;
		}
	}
	for(int i=m;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}