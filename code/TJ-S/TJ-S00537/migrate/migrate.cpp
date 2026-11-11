#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e18;
struct node{
	ll num,step,sna;
};
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ll n,d,l=0,b,ans=0,answer=0;
		scanf("%lld%lld",&n,&d);
		vector<ll> a;
		scanf("%lld",&b);
		a.push_back(b);
		for(int i=1;i<n;i++){
			scanf("%lld",&b);
			a.push_back(b);
			while(b-a[l+1]>d) l++;
			int ans=i-l-1;
			answer+=(!(ans%2)&&ans&&(b-a[l]>d));
		}
		printf("%d\n",answer);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
