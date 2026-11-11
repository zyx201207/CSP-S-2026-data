#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll m;
long long n,tong[N],maxxshu,maxxge=-1,suoxu,shu,ge,ge1=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n<1000){
		vector<ll>a(n+5);
		for(int i=0; i<n; i++){
			ll x;
			scanf("%lld",&x);
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=i; k<j; k++){
					suoxu+=a[j]-a[k];
					ge++;
					if(suoxu>m){
						ge--;
						continue;
					}
				}
				suoxu=0;
				ge1=max(ge,ge1);
				ge=0;
			}
		}
		printf("%lld",ge1);
		return 0;
	}
	for(int i=0; i<n; i++){
		ll x;
		scanf("%lld",&x);
		tong[x]++;
		if(maxxge<tong[x]){
			maxxge=max(tong[x],maxxge);
			maxxshu=x;
		}
		shu=max(x,shu);
	} 
	if(maxxge==1){
		maxxshu=(shu+1)/2;
	}
	long long l=1,r=shu,zhong=maxxshu; 
	while(l!=r){
		for(int i=1; i<=zhong; i++){
			suoxu+=tong[i]*(zhong-i);
			ge+=tong[i];
		}
		if(suoxu==m){
			printf("%lld",ge);
			return 0;
		}
		else if(suoxu>m){
			r=zhong;
			zhong=(l+r)/2;
		}
		else{
			l=zhong;
			zhong=(l+r)/2;
		}
		suoxu=0;
		ge=0;
	}
	for(int i=1; i<=zhong; i++){
			suoxu+=tong[i]*(zhong-i);
			ge+=tong[i];
		}
	printf("%lld",ge);
	return 0;
}
