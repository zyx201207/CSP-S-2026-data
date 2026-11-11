#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long l=1,w=0,ans=1;
	for(int i=2;i<=n;i++){
		w+=(a[i]-a[i-1])*(i-l);
		while(w>m){
			w-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
