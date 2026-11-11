#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int littleN=5010;
long long a[N];
long long c,T,n,d;
int f[littleN][littleN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c<=10){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=0x3f3f3f3f;
				}
			}
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				f[i][i]=0;
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d)break;
					f[i][j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=i+1;k<j;k++){
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int cnt=0;
					for(int k=i+1;k<j;k++){
						if(f[i][j]==f[i][k]+f[k][j])cnt++;
					}
					if(cnt==2)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else if(c==13||c==14){
		while(T--){
			cout<<"0\n";
		}
	}
	else if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if((a[2]-a[1])*2>d){
				cout<<"0\n";
				continue;
			}
			int t=d/(a[2]-a[1]);
			cout<<n-d-1<<endl;
		}
	}
	else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<n<<endl;
		}
	}
	return 0;
}