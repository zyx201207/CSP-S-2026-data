#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;

long long ans[N];
int vis[N];
long long tot=0,ntot=1;
int c,t,n;
long long d,a[N];

void f(int p){
	int i=p-1;
	while(a[p]-a[i]<=d && i>=1){
		ans[p]=min(ans[i]+1,ans[p]);
		i--;
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ans[i]=0x7f7f7f7f7f;
		}
		ans[1]=0ll;
		ans[2]=1ll;
		for(int i=3;i<=n;i++)f(i);
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			vis[i]=1;
			for(int j=i+1;j<=n;j++){
				if(ans[j]==ans[i]){
					ntot++;
					vis[j]=1;
				}
			}
			tot+=ntot*(ntot-1)/2;
			ntot=1;
		}
		printf("%lld\n",tot);
		for(int i=1;i<=n;i++){
			vis[i]=0;
			tot=0;
		}
	}
	return 0;
} 