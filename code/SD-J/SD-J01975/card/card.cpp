#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005],a[500005],v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				v[a[j]]=j;
			}
			else{
				for(int k=v[a[j]];k<j;k++)
					v[a[k]]=0;
				v[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
			if(v[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}

