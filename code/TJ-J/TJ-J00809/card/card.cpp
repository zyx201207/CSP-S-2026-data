#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int id[300005],mn[500005],cl[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int r=i-1;
		for(int j=i;j<=n;j++){
			if(id[a[j]]){
			
				int u=id[a[j]];
				for(int l=id[a[j]];l<=r;l++){
					id[mn[l]]=0;
				}r=u;
				id[a[j]]=u;
			}else {
				mn[++r]=a[j];
				id[a[j]]=r;
			}
		}for(int j=1;j<=m;j++){
			if(id[j])cl[j]++,id[j]=0;
		}
	}for(int i=1;i<=m;i++)cout<<cl[i]<<' ';
	return 0;
}
