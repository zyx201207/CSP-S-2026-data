#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
struct node{
	int x,num;
	bool operator<(const node &ot) const{
		return num>ot.num;
	}
};
int c,t,n,d,ans,cnt,a[N],dis[N][N],num[N][N];
vector<node> g[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;cnt=0;
		int m=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2) m=a[i]-a[i-1];
			if(i>=2&&a[i]-a[i-1]==m) cnt++;
		}
		if(cnt==n-1){
			if(m>d){
				cout<<"0\n";
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d) dis[i][j]=1;
				else dis[i][j]=1e18;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(k<=i||k>=j) continue;
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				num[i][j]=0;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(k<i||k>j) continue;
					if(dis[i][j]==1e18) continue; 
					if(dis[i][j]==dis[i][k]+dis[k][j]) num[i][j]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<dis[i][j]<<" ";
				if(num[i][j]==2) ans++;
			}
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}

