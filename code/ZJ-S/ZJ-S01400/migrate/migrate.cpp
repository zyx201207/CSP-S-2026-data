#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=305;
int c,t;
int n,d;
int a[N];
int st[M][M],num[M][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	
	if(c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			memset(st,0x3f,sizeof st);
			memset(num,0,sizeof num);
			for(int i=1;i<=n;i++){
				st[i][i]=1,num[i][i]=1;
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d)st[i][j]=num[i][j]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						if(st[i][k]+st[k][j]<st[i][j]){
							st[i][j]=st[i][k]+st[k][j];
							num[i][j]=num[i][k]*num[k][j];
						}else if(st[i][k]+st[k][j]==st[i][j] && k!=i && k!=j){
							num[i][j]+=num[i][k]*num[k][j];
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(num[i][j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	if(11<=c && c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(n==1){
				cout<<0<<"\n";
				continue;
			}
			int x=d/(a[2]-a[1]);
		    if(x<=1)cout<<0<<"\n";
		    else{
		    	int y=2*x;
		    	if(y>n)cout<<0<<"\n";
		    	else cout<<n-y+1<<"\n";
			}
		}
		
	}
	return 0;
}

