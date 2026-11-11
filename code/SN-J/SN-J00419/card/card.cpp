#include<bits/stdc++.h>
using namespace std;

int n,a[500005],b[500005],f[300005],cnt[300005],m,idx;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int T=1;T<=n;T++){
		memset(f,0,sizeof f);
		idx=0;
		for(int i=T;i<=n;i++){
			if(f[a[i]]){
				idx=f[a[i]];
			}else{
				b[++idx]=a[i];
				f[a[i]]=idx;
			}
		}
		for(int i=1;i<=idx;i++){
			cnt[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}
/*
4 3
1 2 1 3

*/
