#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,w,a[500010],b[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		w=0;
		for(j=i;j<=n;j++){
			b[++w]=a[j];
			for(k=w-1;k>=1;k--)
				if(b[k]==a[j]) w=k;
		}
		for(j=1;j<=w;j++) ans[b[j]]++;
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

