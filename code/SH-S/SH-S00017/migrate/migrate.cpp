#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=2000010;
ll C,T,n,m,ans;
ll a[MaxN];
ll ca[MaxN];
ll pe[MaxN];
ll qe[MaxN];
ll dpa[MaxN];
ll dpb[MaxN];
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
	//*/
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//*/
	C=readi();T=readi();
	while(T-->0){
		ans=0;
		n=readi();m=readi();
		for(ll i=1;i<=n;i++){
			a[i]=readi();
			ca[i]=0;
		}
		for(ll j=1,i=1;i<=n;i++){
			while((j<n)&&(a[j+1]<=a[i]+m))
				j++;
			pe[i]=j;
		}
		for(ll j=n,i=n;i>=1;i--){
			while((j>1)&&(a[i]-m<=a[j-1]))
				j--;
			qe[i]=j;
		}
		for(ll i=1;i<=n;i++){
			dpa[i]=1;
			if(qe[i]<i){
				dpb[i]+=dpa[qe[i]+1];
				ans+=dpb[i];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
