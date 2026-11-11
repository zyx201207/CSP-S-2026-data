#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace l_mid_r{
	const int N=5e5+5;
	int n,m,a[N],cur,ans;
	int main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",a+i);
		sort(a+1,a+n+1);
		for(int i=2,j=1;i<=n;i++){
			cur+=(a[i]-a[i-1])*(i-j);
			while(cur>m) cur-=a[i]-a[j],j++;
			ans=max(ans,i-j+1);
		}
		printf("%lld\n",ans);
		return 0;
	}
}
signed main(){return l_mid_r::main();}
//~ 5 5
//~ 1 2 4 8 9
