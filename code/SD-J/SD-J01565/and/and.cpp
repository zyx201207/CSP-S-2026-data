#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],m,tot[40],b[N];
bool v[50];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=30;++j){
			if((a[i]>>j)&1==1){
				tot[j]++;
			}
		}
	}
	for(int i=0;i<=30;++i){
		if(tot[i]>=m){
			v[i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=30;++j){
			if((a[i]>>j)&1==1&&v[j]==1){
				b[i]+=(1<<j);
			}
		}
	}
	sort(b+1,b+1+n,cmp);
	int ans=b[1];
	for(int i=2;i<=m;++i){
		ans&=b[i];
	}
	printf("%lld",ans);
	return 0;
}
