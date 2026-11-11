#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int v[500010];
int ans[500010];
int nxt[500010];
int nt(int k){
	if(nxt[nxt[k]]) nxt[k]=nt(nxt[k]);
	return nxt[k];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) v[j]=0;
		for(int j=1;j<=n;j++) nxt[j]=0;
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				v[a[j]]=j;
				ans[a[j]]++;
			}else{
				for(int k=v[a[j]]+1;k<j;k++){
					if(nxt[k]) k=nt(k);
					if(k>=j) break;
					nxt[k]=j;
					ans[a[k]]--;
					v[a[k]]=0;
				}
				nxt[v[a[j]]]=j;
				v[a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
