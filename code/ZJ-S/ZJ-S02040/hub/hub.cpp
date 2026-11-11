#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,a[10001][10001],cnt[10001],unlock[10001],ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long u[100001];
	for(int i=1;i<=10000;i++) u[i]=2*(2*i+1);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)a[i][j]=0;
		for(long long i=1;i<=n;i++){
			cnt[i]=0;unlock[i]=0;ans=0;
		}
		for(long long i=1;i<n;i++){
			long long x,y;
			cin>>x>>y;
			a[x][y]=1;a[y][x]=1;
			cnt[x]+=1;cnt[y]+=1;
		}while(1==1){
			int p=0;
			for(long long i=1;i<=n;i++)if(cnt[i]>2) p=1;
			if(p==0) break;
			ans+=1;
			for(long long i=1;i<=n;i++){
				if(cnt[i]==1&&unlock[i]==0){
					for(long long j=1;j<=n;j++){
						if(a[i][j]==1){
							a[i][j]=0;a[j][i]=0;
							cnt[i]-=1;cnt[j]-=1;
							unlock[j]=1;break;
						}
					}
				}
			}
			for(long long i=1;i<=n;i++)unlock[i]=0;	
		}
		long long s=0;
		for(long long i=1;i<=n;i++)if(cnt[i]!=0) s+=1;
		if(k==1){
			if(s%2==0) s=s/2;
			else s=(s-1)/2;
		}else{
			s=s-(k-2);
			long long l=0;
			for(long long i=1;i<=n;i++){
				if(u[i]<=s) l=i;
				else break;
			}
			s=l+1;
		}	
		cout<<s+ans<<endl;		
	}
	return 0;
}