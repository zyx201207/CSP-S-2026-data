#include<bits/stdc++.h>
using namespace std;
long long a[2000005],f[5005][5005],g[5005][5005],l[2000005],r[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long testid,t;
	cin>>testid>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(testid<=10){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					f[i][j]=1e18,g[i][j]=0;
				}
			}
			long long ans=0;
			for(long long i=1;i<=n;i++){
				f[i][i]=0,g[i][i]=1;
				for(long long j=i+1;j<=n;j++){
					for(long long k=j-1;(k>=i)&&((a[j]-a[k])<=d);k--){
						if((f[i][k]+1)<f[i][j]){
							f[i][j]=f[i][k]+1;
							g[i][j]=g[i][k];
						}
						else if((f[i][k]+1)==f[i][j]){
							g[i][j]+=g[i][k];
						}
					}
					if(g[i][j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
		else if((testid==11)||(testid==12)){
			if(n==1){
				cout<<"0\n";
				continue;
			}
			long long st=d/(a[2]-a[1]);
			if(st<=1){
				cout<<"0\n";
				continue;
			}
			long long len=st*2;
			cout<<max(0ll,n-len+1)<<"\n";
		}
		else{
			long long j=1;
			for(long long i=1;i<=n;i++){
				j=max(j,i);
				while((j<n)&&(a[j+1]-a[i]<=d)){
					j++;
				}
				r[i]=j;
			}
			j=n;
			for(long long i=n;i>=1;i--){
				j=min(j,i);
				while((j>1)&&(a[i]-a[j-1]<=d)){
					j--;
				}
				l[i]=j;
			}
			long long ans=0;
			for(long long i=1;i<=n;i++){
				long long l1=r[i]+1,r1=n;
				long long mid=(l1+r1)>>1ll;
				while(l1<=r1){
					if((r[i]-l[mid]+1)>2){
						l1=mid+1;
					}
					else{
						r1=mid-1;
					}
					mid=(l1+r1)>>1ll;
				}
				long long l2=r[i]+1,r2=n;
				mid=(l2+r2)>>1ll;
				while(l2<=r2){
					if((r[i]-l[mid]+1)>=2){
						l2=mid+1;
					}
					else{
						r2=mid-1;
					}
					mid=(l2+r2)>>1ll;
				}
				ans+=(r2-l1+1);
			}
			cout<<ans<<"\n";
			for(long long i=1;i<=n;i++){
				a[i]=l[i]=r[i]=0;
			}
		}
	}
	return 0;
} 
