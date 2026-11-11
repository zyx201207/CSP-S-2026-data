#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,x[N];
long long tpz;
long long dp[5005][5005];
long long ans[5005][5005];
long long key;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		key=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==2)tpz=x[i]-x[i-1];
			else if(i>2 && tpz && tpz!=x[i]-x[i-1])tpz=0;
		}
		if(n<4){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)dp[i][i]=ans[i][i]=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int k=j-1,cnt=0,mn=0x3f3f3f3f;
				while(k>=i && x[j]-x[k]<=d){
					if(ans[i][k]<mn)
						mn=ans[i][k],cnt=0;
					if(ans[i][k]==mn)
						cnt+=dp[i][k];
					dp[i][j]=cnt,ans[i][j]=mn+1;
					k--;
				}
				if(dp[i][j]==2)key++;
			}
		}
		cout<<key<<endl;
	}
	return 0;
}

