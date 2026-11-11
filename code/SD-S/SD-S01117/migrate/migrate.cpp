#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int x[2000005];
int f[2000005][25];
int get(int u,int v){
	if(u>v)swap(u,v);
	int ans=0;
	for(int i=21;i>=0;i--)if(f[u][i]<v)ans+=(1<<i),u=f[u][i];
	return ans+1;
}
int f2[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(x[mid]-x[i]<=d)l=mid;
				else r=mid-1;
			}
			f[i][0]=l;
		}
		for(int j=1;j<=21;j++)for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f2[i][j]=get(i,j);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=i;k<=j;k++){
					if(f2[i][k]+f2[k][j]==f2[i][j])cnt++;
					if(cnt>f2[i][j])break;
				}
				ans+=(cnt==f2[i][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
