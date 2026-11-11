#include <bits/stdc++.h>
using namespace std;
//struct node{
//	int id,dis;
//	bool operator<(const node&other)const{
//		return dis>other.dis;
//	}
//};
long long x[2000020];
long long dis[330][330];
long long cnt[330][330][330];
long long ans=0;
void init(){
	ans=0;
	for(int i=1;i<=300;i++){
			for(int j=1;j<=300;j++){
                dis[i][j]=100000;
			}
		}
		for(int i=1;i<=300;i++){
			dis[i][i]=0;
		}
		for(int i=1;i<=300;i++){
			for(int j=1;j<=300;j++){
				for(int k=1;k<=300;k++){
					cnt[i][j][k]=0;
				}
			}
		}
}
int main(){
	freopen("migrate.in","r",stdin);
	long long c,t;
	cin>>c>>t;
	if(c<=6){
		
		while(t--){
			init();
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			for(int i=1;i<=n;i++){
				for(int len=1;len<=i;len++){
					int j=i-len;
					if(x[i]-x[j]<=d){
						dis[j][i]=1;
						//cout<<j<<" "<<i<<endl;
						cnt[j][i][1]++;
					}else{
						for(int k=j+1;k<i;k++){
							if(x[k]-x[j]<=d&&x[i]-x[k]<=d){
								cnt[j][i][dis[j][k]+dis[k][i]]++;
								dis[j][i]=min(dis[j][i],dis[j][k]+dis[k][i]);
//								cout<<i<<" "<<j<<" "<<k<<" "<<dis[j][i]<<" "<<dis[j][k]<<" "<<dis[k][i]<<endl;
							}
						}
					}
				}
			}
			for(int i=2;i<=n;i++){
				for(int j=1;j<i;j++){
					if(cnt[j][i][dis[j][i]]==2){
						ans++;
					}
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<i;j++){
//					cout<<dis[j][i]<<" ";
//				}
//				cout<<endl;
//			}
			freopen("migrate.out","w",stdout);
			cout<<ans<<endl;
		}
	}else if(c==11||c==12){
		init();
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int mis=x[2]-x[1];
		if(mis*2>d){
			cout<<0<<endl;
		}else{
			long long k=d/mis;
			cout<<1LL*(n-2*k+1)<<endl;
		}
	}
	return 0;
}
