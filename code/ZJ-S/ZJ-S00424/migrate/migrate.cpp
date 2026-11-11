#include<bits/stdc++.h>
using namespace std;
typedef long long Int;
typedef pair<Int,Int> pir;

Int n,k,p[2000005],l[2000005],r[2000005],lf[2000005],rf[2000005];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(Int i=1;i<=n;i++){
			cin>>p[i];
			lf[i]=rf[i]=0;
		}
		// calculate l,r 
		Int lp=1;
		for(Int i=1;i<=n;i++){
			while(p[i]-p[lp]>k)++lp;
			l[i]=lp;
		}
		Int rp=n;
		for(Int i=n;i>=1;i--){
			while(p[rp]-p[i]>k)--rp;
			r[i]=rp;
		}
		// calculate lf,rf
		for(Int i=1;i<n;i++)lf[i]=l[i+1]-l[i]+(l[i+1]-l[i]!=0)*lf[l[i]];
		for(Int i=n;i>1;i--)rf[i]=r[i]-r[i-1]+(r[i]-r[i-1]!=0)*rf[r[i]];
		// calculate ans
		Int ans=0;
		for(Int i=2;i<n-1;i++){
			ans+=(p[i+2]-p[i]<=k&&p[i+1]-p[i-1]<=k)*((l[i+1]-l[i])?l[i+2]-l[i+1]:lf[i+1])*((r[i+1]-r[i])?r[i]-r[i-1]:rf[i]);
			//cout<<(p[i+2]-p[i]<=k&&p[i+1]-p[i-1]<=k)*((l[i+1]-l[i])?l[i+2]-l[i+1]:lf[i+1])*((r[i+1]-r[i])?r[i]-r[i-1]:rf[i])<<endl;
		}
		cout<<ans<<endl;
	}

	return 0;
}
