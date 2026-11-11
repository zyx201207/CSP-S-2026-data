#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
const int M=300010;
ll n,m;
ll a[N],cnt[M],ans[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		for(ll j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				cnt[a[j]]=j;
			}else{
				for(ll k=cnt[a[j]];k<=j;k++){
					cnt[a[k]]=0;
				}
				cnt[a[j]]=j;
			}
		}
		for(ll j=i;j<=n;j++){
			if(cnt[a[j]]){
				ans[a[j]]++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",ans[a[i]]);
	}
	return 0;
}
