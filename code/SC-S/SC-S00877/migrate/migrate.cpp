#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,l,ans=0;
		cin>>n>>l;
		int dp[305][305],st[305][305];
		memset(st,0,sizeof(st));
		memset(dp,0x3f,sizeof(dp));
		vector<int>a(n);
		for(int i=1;i<=n;i++)cin>>a[i];
		int j=1;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>l)break;
				st[i][j]=1;
				st[j][i]=1;
				dp[i][j]=1;
				dp[j][i]=1;
			}
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				if(l==1){
					dp[i][i]=0;
					continue;
				}
				int j=i+l-1,f=0;
				
				for(int k=i;k<=j;k++){
					if(st[i][k]==0||st[k][j]==0)continue;
					int v=dp[i][k]+dp[k][j];
					if(v>=0x3f)continue;
					if(v<dp[i][j]){
						if(f==2)ans--;
						if(f>2)ans++;
						f=1;
						dp[i][j]=l;
					}
					else if(dp[i][j]==v){
						if(f==1)ans++,f++;
						else if(f==2)ans--,f++;
						else if(f>2)f++;
					}
				} 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
