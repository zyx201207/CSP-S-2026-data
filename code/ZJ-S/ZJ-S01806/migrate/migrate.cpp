#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[2000010];
int f[5010][5010],cnt[5010][5010];

void calc(){
	memset(f,0x3f,sizeof(f));
	memset(cnt,0,sizeof(cnt));
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i][i]=0;
		cnt[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=k) f[i][j]=1,cnt[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || j==k || i==k) continue;
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || j==k || i==k) continue;
				if(f[i][j]==f[i][k]+f[k][j]){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int d=abs(a[2]-a[1]);
			int p=k/d;
			if(p<2) cout<<"0"<<endl;
			else cout<<max(0ll,n-2*p+1)<<endl;
		}
	}
	else{
		while(t--){
			calc();
		}
	}
	return 0;
}

