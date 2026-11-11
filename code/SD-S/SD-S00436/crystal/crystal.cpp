#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
struct node{
	int a,p;
	friend bool operator < (node x,node y){
		return x.a<y.a;
	}
}f[500005];
int sum(int l,int r){
	return f[r].p-f[l-1].p;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&f[i].a);
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++){
		f[i].p=f[i].a+f[i-1].p;
	}
	int j=1;
	for(int i=1;i<=n;i++){
		int k=f[i].a*(i-j+1);
		int d=k-sum(j,i);
		if(d>m){
			for(int jj=j+1;jj<=i;jj++){
				k=f[i].a*(i-jj+1);
				int dd=k-sum(jj,i);
				if(dd<=m){
					j=jj;
					break;
				}
			}
		}
		ans=max(ans,(i-j+1));
	}
	printf("%lld",ans);
	return 0;
} 
