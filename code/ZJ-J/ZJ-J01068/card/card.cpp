#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,cnt,a[500010],b[300010],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=500){
		for(i=1;i<=n;i++){
			cnt=0;
			for(j=i;j<=n;j++){
				b[++cnt]=a[j];
				for(k=1;k<=cnt;k++)
					if(b[k]==a[j]){
						cnt=k;
						break;
					}
			}
			for(j=1;j<=cnt;j++) ans[b[j]]++;
		}
		for(i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(m<=2){
		ans[a[n]]=n;
		if(m==1){
			cout<<ans[1];
			return 0;
		}
		else{
			if(a[n]==1){
				for(i=1;i<=n;i++)
					if(a[i]==2) ans[2]++;
				cout<<ans[1]<<" "<<ans[2];
				return 0;
			}
			else{
				for(i=1;i<=n;i++)
					if(a[i]==1) ans[1]++;
				cout<<ans[1]<<" "<<ans[2];
				return 0;
			}
		}
	}
	for(i=1;i<=n;i++) ans[a[i]]=i;
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
}
