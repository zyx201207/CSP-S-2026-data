#include<bits/stdc++.h>
#define int long long
#define maxn 5005
using namespace std;
int C,T,n,d;
int a[maxn];
int dis[maxn][maxn];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int cnt=0;
		for(int j=i+1;j<=n;j++){
			if(a[i]+d*cnt<a[j]){
				cnt++;
				if(a[i]+d*cnt<a[j]){
					break;
				}
			}
			dis[i][j]=dis[j][i]=cnt;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		init();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(dis[i][j]==-1)continue;
//				cout<<i<<" "<<j<<":\n";
				int len=(j-i-1);
				int cnt=0;
				for(int s=1;s<(1<<len);s++){
					int x=s;
					vector<int>v;
					while(x){
						v.push_back(x&1);
						x>>=1;
					}
					int sum=0,lst=i;
					for(int k=0;k<v.size();k++){
						if(v[k]){
							sum+=dis[lst][i+k+1];
							lst=i+k+1;
//							cout<<lst<<" ";
						}
					}
					sum+=dis[lst][j];
//					cout<<"sum:"<<sum<<"\n";
//					cout<<"\n-------\n";
					cnt+=(sum==dis[i][j]);
				}
				ans+=(cnt==2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
