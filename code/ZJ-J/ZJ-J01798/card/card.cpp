#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,s[500010],a[500010],cnt,f[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		cnt=0;
		for(j=i;j<=n;j++){
			for(k=1;k<=cnt;k++){
				if(s[k]==a[j]){
					cnt=k;
					break;
				}
			}
			if(k>cnt) s[++cnt]=a[j];
		}
		for(j=1;j<=cnt;j++) f[s[j]]++;
	}
	for(i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}

