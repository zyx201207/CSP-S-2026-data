#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
#define int long long 
const int QwQ=5e12+5;
int C,T;
int n,d;
int a[MAXN];
int t[MAXN];//第i个表示i~i+1的差 
int s[MAXN];//s[i]-s[j]表示i+1~j+1的差
            //s[i-1]-s[j-1]是i~j的差 
int dp[MAXN];
int flag[MAXN];
void dfs(int nowx){
	if(nowx==n){
		return;
	}
	for(int i=nowx+1;i<=n;i++){
		int temp=s[i-1]-s[nowx-1];
		if(temp>d){
			break;
		}
		if(flag[nowx]+1<flag[i]){
			flag[i]=flag[nowx]+1;
			dp[i]=0;
		}
		if(flag[nowx]+1==flag[i]){
			dp[i]++;
		}
		dfs(i);
	}
}
signed main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	for(int ii=1;ii<=T;ii++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			t[i]=a[i+1]-a[i];
		}
		for(int i=1;i<n;i++){
			s[i]=s[i-1]+t[i];
		}
		int ans=0;
		for(int iii=1;iii<=n-2;iii++){
			for(int i=0;i<=n;i++){
				dp[i]=1;
				flag[i]=QwQ;
			}
			flag[iii]=0;
			dfs(iii);
			for(int i=iii;i<=n;i++){
				if(dp[i]==2){
					ans++;
				}
			}			
		}
		cout<<ans<<endl;	
	}
	return 0;
}