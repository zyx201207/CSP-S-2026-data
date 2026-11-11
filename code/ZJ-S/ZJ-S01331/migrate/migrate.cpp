#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n,m,a[2000005],d[2005][2005],f[2005][2005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int type,T;
	cin>>type>>T;
	if(type>=13&&type<=14){
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			int l=1,r=n;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=m) l=i;
				else break;
			}
			for(int i=n;i>=1;i--){
				if(a[n]-a[i]<=m) r=i;
				else break;
			}
			int ans=0;
			for(int i=1,j=0,jj=0;i<=n;i++){
				while(j<n&&a[j+1]-a[i]<=m) j++;
				while(jj<n&&a[jj+1]-a[j]<=m) jj++;
				if(i>=r&&i<=l) continue;
				ans+=jj-j;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) d[i][j]=0,f[i][j]=1;
				else d[i][j]=0x3f3f3f3f3f3f3f3f,f[i][j]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(a[j]-a[k]>m) break;
					if(d[i][k]+1<d[i][j]) d[i][j]=d[i][k]+1,f[i][j]=f[i][k];
					else if(d[i][k]+1==d[i][j]) f[i][j]+=f[i][k],f[i][j]=min(f[i][j],3ll);
				}
				if(f[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}