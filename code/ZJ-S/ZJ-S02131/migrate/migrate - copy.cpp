#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for(i=(a);i<=(b);i++)
#define G(i,a,b) for(i=(a);i>=(b);i--)
#define clr(a) memset((a),0,(n+5)*sizeof(ll))
using namespace std;
const ll _=2e6+5,inf=1e18;
ll ID,N,n,k,t,s,a[_],bl[_],br[_],cl[_],cr[_],dl[_],dr[_],i,j;
void P(){
	cin>>n>>k;s=0;a[0]=-inf;a[n+1]=inf;
	F(i,1,n)cin>>a[i];
	clr(bl);clr(br);clr(cl);clr(cr);clr(dl);clr(dr);
	F(i,j=1,n){while(a[j]<a[i]-k)j++;bl[i]=j;}
	G(i,j=n,1){while(a[j]>a[i]+k)j--;br[i]=j;}
//F(i,1,n)cout<<bl[i]<<" \n"[i==n];
//F(i,1,n)cout<<br[i]<<" \n"[i==n];
	F(i,1,n)cl[i]=cr[i]=1;
	F(i,1,n)cl[br[i]]+=(br[i]!=i&&bl[br[i]]<=i);
	G(i,n,1)cr[bl[i]]+=(bl[i]!=i&&br[bl[i]]>=i);
//F(i,1,n)cout<<cl[i]<<" \n"[i==n];
//F(i,1,n)cout<<cr[i]<<" \n"[i==n];
	F(i,1,n)if(br[i]!=i&&bl[br[i]]==i)cl[br[i]]+=cl[i]-1;
	G(i,n,1)if(bl[i]!=i&&br[bl[i]]==i)cr[bl[i]]+=cr[i]-1;
//F(i,1,n)cout<<cl[i]<<" \n"[i==n];
//F(i,1,n)cout<<cr[i]<<" \n"[i==n];
	F(i,2,n)if(bl[i-1]!=i-1&&br[bl[i-1]]==i&&br[i]!=i&&bl[br[i]]==i-1)
		s+=cl[bl[i-1]]*cr[br[i]]-1;//,cout<<bl[i-1]<<' '<<i-1<<' '<<i<<' '<<br[i]<<'\n';
	F(i,1,n)dl[br[i]]+=(br[i]>i+1),dr[bl[i]]+=(bl[i]<i-1);
//F(i,1,n)cout<<dl[i]<<" \n"[i==n];
//F(i,1,n)cout<<dr[i]<<" \n"[i==n];
	F(i,2,n)s+=dl[i]*dr[i-1];
//cout<<'\n';
	cout<<s<<'\n';
//cout<<"--------------------\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ID>>N;while(N--)P();
}
