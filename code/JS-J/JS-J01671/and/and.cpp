#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int z=200009;
int n,a[2][z],l[2],ans,c,m,t,sz;

void solve(){
	for(int i=30;i>=0;i--){
		l[t^1]=c=0;
		for(int j=1;j<=l[t];j++)
			c+=(a[t][j]>>i)&1;
//		printf("%lld %lld\n",i,c);
		if(c>=m){
			ans+=1<<i;
			for(int j=1;j<=l[t];++j)
				if((a[t][j]>>i)&1)
					a[t^1][++l[t^1]]=a[t][j];
		}else{
			for(int i=1;i<=l[t];++i)
				a[t^1][++l[t^1]]=a[t][i];
		}
//		printf("lt=%lld lt^1=%lld\n",l[t],l[t^1]);
		t^=1;
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[0][i]);
    sz=n;
    l[0]=n;
    solve();
    printf("%lld",ans);
}
