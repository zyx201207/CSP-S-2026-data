#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;++i){
		bool f[300010];
		memset(f,0,sizeof(f));
		for(int j=i;j<n;++j){
			if(f[a[j]]){
				for(int k=j-1;k>=i;--k){
					if(a[k]==a[j])break;
					f[a[k]]=false;
				}
			}
			else{
				f[a[j]]=true;
			}
		}
		for(int j=1;j<=m;++j){
			if(f[j])++ans[j];
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}