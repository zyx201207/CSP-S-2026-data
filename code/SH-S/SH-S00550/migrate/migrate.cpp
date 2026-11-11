#include<bits/stdc++.h>
using namespace std;
int f[310][310],cnt[310][310];
long long a[2000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int n;
			long long d;
			memset(cnt,0,sizeof cnt);
			memset(f,0x3f,sizeof f);
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				f[i][i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(a[i]-a[j])<=d) f[i][j]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(abs(a[i]-a[k])<=d && abs(a[j]-a[k])<=d && k>i && k<j && j>i){
							if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
						}
					}
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(abs(a[i]-a[k])<=d && abs(a[j]-a[k])<=d && k>i && k<j && j>i){
							if(f[i][j]==f[i][k]+f[k][j]) cnt[i][j]++;
						}
					}
				}
			}
			int cntx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2) cntx++;
				}
			}
			cout<<cntx<<"\n";
		}
	}
	return 0;
}

