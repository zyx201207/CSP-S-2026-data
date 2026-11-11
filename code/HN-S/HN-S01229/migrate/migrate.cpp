#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t,n,d,shu,ge; 
vector<ll> a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(long long i=0; i<n; i++){
			ll x;
			scanf("%lld",&x);
			a.push_back(x);
		}
		for(int i=0,j=0; i<n,j<n; i++,j++){
			while(a[j]-a[i]<=d&&j<=n){
				j++;
			}
			j--;
			int k=j;
			while((a[k]-a[j-1]<=d))k++;
			int l=k;
			while(a[l]-a[j]<=d)l++;
			if(l==k){
				l--;
				for(k; k<n; k++){
					if(a[k]-a[l]>d){
						k--;
						break;
					}
				}
				ge+=k-l+1;
				j++;
			}else i++;
		}
		printf("%lld\n",ge);
		a.clear();
		ge=0;
	}
	return 0;
}

