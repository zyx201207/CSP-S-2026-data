#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(i=(a);i<=(b);i++)
#define G(i,a,b) for(i=(a);i>=(b);i--)
#define clr(a) memset((a),0,(n+5)*sizeof(ll))
using namespace std;
const ll _=2e6+5,inf=1e18;
ll ID,N,n,k,t,s,a[_],bl[_],br[_],cl[_],cr[_],i,j;
void P(){
	cin>>n>>k;s=0;a[0]=-inf;a[n+1]=inf;
	F(i,1,n)cin>>a[i];
	clr(bl);clr(br);clr(cl);clr(cr);
	F(i,1,n){
		bl[i]=lower_bound(a+1,a+n+1,a[i]-k)-a;
		br[i]=upper_bound(a+1,a+n+1,a[i]+k)-a-1;
	}
	F(i,1,n){
		cl[i]=cr[i]=t=i;
		F(j,i+1,n){
			if(a[j]>a[j-1]+k)break;
			if(a[j]>a[t]+k)t=j-1;
			cr[j]=cr[t]+j;cl[j]=cl[max(i,bl[j])]+j;
			s+=(cr[j]-cl[j]==1);
		}
	}
	cout<<s<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ID>>N;while(N--)P();
}
