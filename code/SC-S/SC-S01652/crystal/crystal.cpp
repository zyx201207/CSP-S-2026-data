#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
const int N=5e5+5,mod=998244353;
int n,answer;
ll m,a[N],pre[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			ll add=1LL*a[i]*(i-mid+1)-(pre[i]-pre[mid-1]);
			if(add<=m){
				r=mid;
			} else{
				l=mid;
			}
		}
		answer=max(answer,i-r+1);
	}
	printf("%d\n",answer);
	return 0;
}