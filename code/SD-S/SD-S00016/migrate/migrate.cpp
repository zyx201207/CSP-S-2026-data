#include<bits/stdc++.h>
using namespace std;
int c,T,n,r[2000005],l[2000005],lsum[2000005],rsum[2000005],f[5005][5005];
bool vis[5005];
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>x[i],lsum[i]=rsum[i]=1;
		for(int i=1;i<=n;i++){
			r[i]=r[i-1];
			while(r[i]<n&&x[r[i]+1]-x[i]<=d)	r[i]++;
		}
		l[n+1]=n;
		for(int i=n;i>=1;i--){
			l[i]=l[i+1];
			while(l[i]>1&&x[i]-x[l[i]-1]<=d)	l[i]--;
		}
		long long ans=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)	f[i][j]=1e9;
			for(int i=n;i>=1;i--){
				vector<int>g;
				for(int j=i;r[j]!=j;j=r[j]){
					for(int k=j+1;k<=r[j];k++)	f[i][k]=f[i][j]+1;
					g.push_back(r[j]);
					vis[r[j]]=1;
				}
//			//	if(i==1)	for(int k:g)	cout<<k<<' ';	
				for(int j=r[i]+1;j<=n;j++){
					if(f[i][j]>n)	continue;
					int cnt=0;
					for(int k:g){
//						if(k<=i)	continue;
						if(k-2>j)	break;
						if(k-1>i&&k-1<j&&!vis[k-1]&&f[i][k-1]+f[k-1][j]==f[i][j])	cnt++;
						if(k-2>i&&k-2<j&&!vis[k-1]&&!vis[k-2]&&f[i][k-2]+f[k-2][j]==f[i][j])	cnt++;
					}
//					for(int k=i+1;k<j;k++)	if((vis[k+1]||vis[k+2])&&!vis[k]&&f[i][k]+f[k][j]==f[i][j])	cnt++;
//					for(int k:g){
//						if(f[i][k-1]+f[k-1][j]==f[i][j]&&!vis[k-1])	cnt++,vis[k-1]=1;//cout<<i<<' '<<k-1<<' '<<j<<'\n';
//						if(cnt>1||k-2>i&&f[i][k-2]+f[k-2][j]==f[i][j]&&!vis[k-2]){
////							cout<<k-2;
//							cnt=2;
//							break;
//						}	
//					}
					if(cnt==1)	ans++;
				}
				for(int k:g)	vis[k]=0;
		}		
//			for(int i=1;i<=n;i++){
//				for(int j=i;j<=n;j++)	cout<<f[i][j]<<' ';
//				cout<<'\n';
//			}
//			for(int i=1;i<=n;i++)
//				for(int j=i+1;j<=n;j++){
//					
//				}
//					if(f[i][j]==2&&f[r[i]-1][j]==1&&f[r[i]-2][j]>1)	ans++;
		
//		cout<<ans<<' ';
//		for(int i=n;i>=1;i--)
//			if(l[r[i]]==i)	rsum[i]+=rsum[r[i]];
//		for(int i=1;i<=n;i++)
//			if(r[l[i]]==i)	lsum[i]+=lsum[l[i]];
//		for(int i=1;i<=n;i++)	cout<<rsum[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=n;i++)	cout<<lsum[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=n;i++){
////			ans+=r[r[i]-1]-max(r[r[i]-2],r[i]);
//			if(x[r[r[i]]]-x[i]>d&&r[r[i]]==r[r[i]-1]&&r[r[i]]!=r[r[i]-2]){
////				cout<<i<<' '<<r[r[i]]<<'\n';
//				ans+=lsum[i]*rsum[r[r[i]]]-1;
//			}	
//		}
		cout<<ans<<'\n';
	}
	return 0;
}
