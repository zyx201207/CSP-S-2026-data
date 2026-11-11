#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,N,D,a[305],Ans,fy[305][305],cnt[305][305];
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		Ans=0;
		cin>>N>>D;
		for(int i=1;i<=N;i++){
			cin>>a[i];
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(i!=j)fy[i][j]=2e18;
				else fy[i][j]=0ll;
				cnt[i][j]=1ll;
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=i+1;j<=N;j++){
				if(a[j]-a[i]<=D){
					fy[i][j]=1;
				}else{
					break;
				}
			}
		}
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					if(i>=k||k>j)continue;
					if(fy[i][k]+fy[k][j]==fy[i][j]){
						cnt[i][j]++;
					}else if(fy[i][k]+fy[k][j]<fy[i][j]){
						fy[i][j]=fy[i][k]+fy[k][j];
						cnt[i][j]=1;
					}
				}
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=i+1;j<=N;j++){
				if(cnt[i][j]!=2&&fy[i][j]!=1&&fy[i][j]!=(int)2e18){
					Ans++;
				}
			}
		}
		cout<<Ans<<endl;
	}
	return 0;
} 
