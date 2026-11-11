#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long n,m,a[200010],ans=0;
bool f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int k=30;k>=0;k--){
		int s=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1) continue;
			if((a[i]>>k)&1) s++;
		}
		if(s>=m){
			ans+=1<<k;
			for(int i=1;i<=n;i++){
				if(!((a[i]>>k)&1)) f[i]=1;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}