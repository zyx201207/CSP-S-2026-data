#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ma;
long long dfs(int x,int y,long long da) {
	long long maa=0;
	if(x>m) {
		return da;
	}
	if(x==1) {
		for(int i=y+1;i<=n;i++) {
			maa=max(maa,dfs(x+1,i,a[i]));
		}	
	}
	else {
		for(int i=y+1;i<=n;i++) {
			maa=max(maa,dfs(x+1,i,a[i]&da));
		}	
	}
	return maa;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	if(m==2) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				ma=max(ma,a[i]&a[j]);
			}
		}
		printf("%lld\n",ma);
	}
	else if(m==1) {
		for(int i=1;i<=n;i++) {
			ma=max(ma,a[i]);
		}
		printf("%lld\n",ma);
	}
	else {
		printf("%lld\n",dfs(1,0,0));
	}
	return 0;
}
