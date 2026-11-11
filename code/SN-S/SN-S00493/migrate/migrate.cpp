//SN-S00493
//程思阳
//西安市铁一中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e18;
int ty,T,n,d,a[N],nt[N],pr[N],f[N],g[N],si[N],sj[N],t[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>ty>>T;T--;){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],t[i]=0;
		for(int i=1,j=1;i<=n;i++){
			if(j<i) j=i;
			while(j<n&&a[j+1]-a[i]<=d) j++;
			nt[i]=j;
		}
		for(int i=n,j=n;i;i--){
			if(j>i) j=i;
			while(j>1&&a[i]-a[j-1]<=d) j--;
			pr[i]=j;
		}
		for(int i=1;i<=n;i++){
			int ii=i;
			si[i]=1;
			if(ii>1&&pr[ii]!=ii&&nt[pr[ii]]==ii) si[i]+=min(ii,pr[ii+1]-pr[ii]);
			if(nt[pr[ii]]==ii) si[i]+=si[pr[ii]]-1;
		}
		for(int j=n;j;j--){
			int jj=j;
			sj[j]=1;
			if(jj<n&&nt[jj]!=jj&&pr[nt[jj]]==jj) sj[j]+=nt[jj]-max(jj,nt[jj-1]);
			if(pr[nt[jj]]==jj) sj[j]+=sj[nt[jj]]-1;
		}
		int re=0;
		for(int i=1;i<=n;i++){
			int j=nt[nt[i]];
			if(j>=i+2&&nt[i]==pr[j]+1){
				if(pr[pr[j]]==i) re+=si[i]*sj[j]-1;
				else re+=sj[j]-1;
			}
		}
		for(int j=1;j<=n;j++){
			int i=pr[pr[j]];
			if(j>=i+2&&nt[i]==pr[j]+1){
				if(nt[nt[i]]==j);
				else re+=si[i]-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(i>2&&nt[i-2]-1>=1) t[nt[i-2]-1]++;
			re+=t[pr[i]];
		}
		cout<<re<<endl;
	}
}
