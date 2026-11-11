#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=500010;
ll n,m,ans=1;
ll a[MaxN];
inline ll readi(){
	char rc;short ry=1;ll rx;
	for(rc=getchar();(rc<'0')||('9'<rc);rc=getchar()){
		if(rc=='-')
			ry=-1;
	}
	for(rx=0;('0'<=rc)&&(rc<='9');rc=getchar())
		rx=rx*10+(rc^'0');
	return ry*rx;
}
int main(){
	ll rx=0;
	//*/
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//*/
	n=readi();m=readi();
	for(ll i=1;i<=n;i++)
		a[i]=readi();
	sort(a+1,a+n+1);
	for(ll j=1,i=2;i<=n;i++){
		rx+=(i-j)*(a[i]-a[i-1]);
		while(rx>m){
			rx-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
