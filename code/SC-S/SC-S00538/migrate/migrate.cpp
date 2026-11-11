#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,cnt,a[2000005],lf[2000005],rf[2000005],f1[2000005],f2[2000005],g1[2000005],g2[2000005],d[2000005],dd[2000005],ans,l,r,s[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		s[n+1]=s[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f1[i]=g1[i]=0;
			f2[i]=g2[i]=9e18;
		}
		r=1,l=n;
		for(int i=1;i<=n;i++){
			while(a[r+1]-a[i]<=m&&r<n){
				r++;
			}
			lf[i]=r;
		}
		d[n]=dd[1]=0;
		for(int i=n-1;i>=1;i--){
			d[i]=d[lf[i]]+1;
		}
		for(int i=n;i>=1;i--){
			while(a[i]-a[l-1]<=m&&l>1){
				l--;
			}
			rf[i]=l;
		}
		for(int i=1;i<=n;i++){
			dd[i]=dd[rf[i]]+1;
		}
		l=1,f1[1]=f2[1]=1;
		for(int i=2;i<=n;i++){
			f1[i]=1;
			while(a[i]-a[l]>m){
				l++;
			}
			if(f2[l]==f2[l+1]||d[i]==d[l]){
				f2[i]=f2[l]+1;
			}
			else{
				f1[i]+=f1[l];
				f2[i]=f2[l]+1;
			}
			//cout<<f1[i]<<" ";
		}
		//cout<<"\n";
		r=n;
		s[n]=1;
		g1[n]=g2[n]=1;
		for(int i=n-1;i>=1;i--){
			g1[i]=1;
			while(a[r]-a[i]>m){
				r--;
			}
			if(g2[r]==g2[r-1]||dd[i]==dd[r]){
				g2[i]=g2[r]+1;
			}
			else{
				g1[i]+=g1[r];
				g2[i]=g2[r]+1;
			}
			s[i]=s[i+1]+g1[i];
			//cout<<g1[i]<<" ";
		}
		//cout<<"\n";
		for(int i=1;i<=n-3;i++){
			int xb=lf[lf[i]-1],xb1=lf[lf[i]-2]+1;
			ans+=f1[i]*max((s[xb1]-s[xb+1]),0ll);
			//cout<<xb<<" "<<xb1<<" "<<ans<<"\n";
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
} 