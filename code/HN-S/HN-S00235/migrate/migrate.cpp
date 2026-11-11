#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,inf=1e18;
int C,T,n,d,a[N],s[N],f[N],g[N],ans,Ans[N];
int sum[N],val[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>s[i];
	if(C<=6){
		ans=0;
		for(int i=1;i<=n;i++){
			f[i]=1,g[i]=1;
			for(int j=i+1;j<=n;j++){
				f[j]=inf;
				g[j]=0;
				for(int k=j;k>=i;k--){
					if(s[j]-s[k]>d)break;
					if(f[k]+1<f[j]){
						f[j]=f[k]+1;
						g[j]=g[k];
					}else if(f[k]+1==f[j])g[j]+=g[k];
				}
				if(g[j]==2)++ans;
//				cout<<i<<" "<<j<<" "<<f[j]<<" "<<g[j]<<"\n";
			}
		}
		cout<<ans<<"\n";
		return;
	}
	if(7<=C&&C<=10){
		for(int i=1;i<n;i++)a[i]=s[i+1]-s[i];
		for(int i=1;i<n;i++)s[i]=a[i];
		--n;
//		for(int i=1;i<=n;i++)cout<<s[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i];
		for(int i=1;i<=n;i++)val[i]=sum[i-1];
		for(int i=2;i<n;i++){
			int l=lower_bound(val+1,val+i,sum[i]-d)-val;
			int r=lower_bound(val+1,val+i,sum[i+1]-d)-val-1;
			Ans[i]=max(0ll,r-l+1);
//			cout<<l<<" "<<r<<" "<<sum[i]-d<<" "<<sum[i+1]-d<<"\n";
		}
		for(int i=1;i<=n;i++)val[i]=sum[i];
		for(int i=2;i<n;i++){
			int l=upper_bound(val+i+1,val+1+n,d+sum[i-2])-val;
			int r=upper_bound(val+i+1,val+1+n,d+sum[i-1])-val-1;
			
			Ans[i]=Ans[i]*max(0ll,r-l+1);
//			cout<<l<<" "<<r<<" "<<d+sum[i-2]<<" "<<sum[i-1]+d<<"\n";
//			cout<<Ans[i]<<" ";
//			cout<<"\n";
		}
		ans=0;
		for(int i=2;i<n;i++)ans+=Ans[i];
		cout<<ans<<"\n";
		return;
	} 
	if(11<=C&&C<=12){
		if(n==1){
			cout<<0<<"\n";
			return;
		}
		int D=s[2]-s[1];
//		7->1 -6
//		1->x +x-1
		if(d<2*D){
			cout<<0<<"\n";
			return;
		}else{
			int st=n-D+D-3;
			d-=2*D;
			st-=d/D*2;
			cout<<max(0ll,st)<<"\n";
		}
		return; 
	}
	cout<<0<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)solve(); 
	return 0;
}

