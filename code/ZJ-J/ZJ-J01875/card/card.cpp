#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll num[N],ans[N];
ll cnt[N];
ll bnt[N];
int main(){
	freopen("card6.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
		cnt[num[i]]=i;
	}int h=0;
	for(int i=0;i<=n;i++){
		bnt[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(cnt[num[i]]==i){
			h+=bnt[i];
			ans[num[i]]+=h;
		}else{
			bnt[cnt[num[i]]]+=h+bnt[i];
			h=0;
		}
	}for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}

