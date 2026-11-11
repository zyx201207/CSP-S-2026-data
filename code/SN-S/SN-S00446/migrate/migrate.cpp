//ZHS 00446 
#include<bits/stdc++.h>
#define int long long
#define maxn 5005
#define INF 1145141919819
using namespace std;
int n,a[maxn],mn[maxn][maxn],num[maxn][maxn],c,t,d;
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mn[i][j]=INF,num[i][j]=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn[i][i]=0,num[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)if(a[i]-a[j]<=d)
			mn[i][j]=1,num[i][j]=1;
		for(int j=i+1;j<=n;j++)if(a[j]-a[i]<=d)
			mn[i][j]=1,num[i][j]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(i==j)continue;
				if(mn[i][k]+mn[j][k]<mn[i][j]){
					mn[i][j]=mn[i][k]+mn[j][k];
					num[i][j]=num[i][k]*num[j][k];
					num[i][j]=min(num[i][j],(int)maxn);
					continue;
				}
				if(mn[i][k]+mn[j][k]==mn[i][j]){
					num[i][j]+=num[i][k]*num[j][k];
					num[i][j]=min(num[i][j],(int)maxn);
					continue;
				}
			}
		}
	}
	int ans=0;
//	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(num[i][j]==2)ans++;
//			cout<<num[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)work();
	return 0;
}
