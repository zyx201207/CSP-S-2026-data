#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,a[500010],f[300010],last[300010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	last[a[n]]=n;f[a[n]]=1;
	for(i=n-1;i>=1;i--){
		if(last[a[i]]==0){
			for(j=i;j<=n;j++){
				if(last[a[j]]!=j&&last[a[j]]!=0) j=last[a[j]];
				f[a[j]]++;
			}
			last[a[i]]=i;
		}
		else
			for(j=last[a[i]];j<=n;j++){
				if(last[a[j]]!=j&&last[a[j]]!=0) j=last[a[j]];
				f[a[j]]++;
			}
	}
	for(i=1;i<=m;i++)
		cout<<f[i]<<" ";
}
