#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n;
ll a[N];char s[N];
ll ans=0;
int main(){
	//freopen("string.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&s[i]);
	}
	int L=1,R=n;
	while(L<R){
		if(s[L]!=s[R]){
			if(a[L]<a[R]){
				ans+=a[L];
				a[R]-=a[L];
				L++;
			}else if(a[L]>a[R]){
				ans+=a[R];
				a[L]-=a[R];
				R--;
			}else{
				ans+=a[L];
				L++;
				R--;
			}
		}else{
			if(a[L]<a[R]){
				a[R]-=a[L];
				L++;
			}else if(a[L]>a[R]){
				a[L]-=a[R];
				R--;
			}else{
				L++;
				R--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
