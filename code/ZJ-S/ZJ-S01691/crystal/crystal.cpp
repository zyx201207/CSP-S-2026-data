#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;

int n,m,a[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int cnt=1,lft=m;
			for(int j=i-1;j>=0;j--){
				if(lft<(a[i]-a[j])){
					ans=max(ans,cnt);
					break;
				}
				else{
					lft-=(a[i]-a[j]);
					cnt++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	else{
		int d=a[2]-a[1];
		int i=1;
		for(i=1;i<n;i++){
			if(i*(i+1)>2*m/d){
				i--;
				break;
			}
		}
		printf("%lld\n",min(n,i+1));
	}
	return 0;
}