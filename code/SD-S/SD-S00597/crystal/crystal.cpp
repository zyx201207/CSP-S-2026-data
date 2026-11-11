#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,ans=1;
ll a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll tmp=m;
	int l=1,r=2;
	int tans=1;
	for(;r<=n;r++){
		tans++;
		tmp-=(r-l)*(a[r]-a[r-1]);
		while(tmp<0&&l<r){
			tmp+=(a[r]-a[l]);
			tans--;
			l++;
		}
		ans=max(ans,tans);
	}
	printf("%d",ans);
	return 0;
}

