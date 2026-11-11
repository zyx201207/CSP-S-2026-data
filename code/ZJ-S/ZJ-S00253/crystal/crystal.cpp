#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500001],pre[500001];
bool check(int q){
	for(int i=q;i<=n;++i){
		if(q*a[i]<=pre[i]-pre[i-q]+m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n;
	int mid=(r+l)>>1;
	while(l+1<r){
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
		mid=(l+r)>>1;
//		cout<<mid<<endl;
	}
	if(r==l+1){
		if(check(r))printf("%d",r);
		else printf("%d",l);
	}
	else printf("%d",mid);
}
