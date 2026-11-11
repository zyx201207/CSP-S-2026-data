#include <bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=5e5+10;

ll n,m;
ll arr[N];
ll c[N];
ll d;

bool check(int x){
	int sum=0;
	for (int i=1;i<=x;i++){
		sum+=arr[x]-arr[i];
		if (sum>m){
			return false;
		}
	}
	return sum<=m;
}

int main (){
	freopen("crystal.in","r",stdin);
	freopen ("crystal.out","w",	stdout);
	scanf ("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&arr[i]);
		if (d!=-1&&i>1){
			d=(d==arr[i]-arr[i-1]?arr[i]-arr[i-1]:-1);
		}
	}
	if (d!=-1){
		ll sum=0;
		for (int i=1;i<=n;i++){
			sum+=(i-1)*d;
			if (sum>m){
				printf ("%d",i-1);
				break;
			}
		}
		if (sum<=m){
			printf ("%lld",n);
		}
	}else {
		sort(arr+1,arr+1+n);
		c[1]=0;
		for (int i=2;i<=n;i++){
			c[i]=c[i-1]+(i-1)*(arr[i]-arr[i-1]);
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				ll tmp=(ll)c[j]-c[i-1]-(i-1)*(arr[j]-arr[i-1]);
				if (tmp<=m){
					ans=max(ans,j-i+1);
				}
				if (ans==n){
					break;
				}
			}
			if (ans==n){
				break;
			}
		}
		printf ("%d",ans);
	}
	
	
	return 0;
} 
