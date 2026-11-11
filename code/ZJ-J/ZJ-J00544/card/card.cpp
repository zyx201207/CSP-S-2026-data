#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],tn[M],st[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tn[a[i]]+=i;
	}
	for(int i=1;i<=n;i++){
		memset(st,0,sizeof(st));
		for(int j=i;j<=n;j++){
			if(st[a[j]]!=0){
				for(int k=st[a[j]];k<j;k++){
					if(st[a[k]]!=0) tn[a[k]]--;
					st[a[k]]=0;
				}
			}
			st[a[j]]=j;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",tn[i]);
	return 0;
}