#include<bits/stdc++.h>
using namespace std;
int a[2000010],dp[2000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen(/*记得写*/".in","r",stdin);
//	freopen(/*记得写*/".out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			if(a[2]-a[1]>d) cout<<"0\n";
			else{
				int b=d/(a[2]-a[1]),ans=0;
				memset(dp,0,sizeof(dp));
				dp[1]=1;dp[2]=1;
				for(int i=3;i<=b;++i){
					for(int j=1;j<i;++j){
						dp[i]+=dp[j];
					}
				}
				for(int i=b+1;i<=n;++i){
					for(int j=i-b;j<i;++j){
						dp[i]+=dp[j];
					}
					if(dp[i]==2) ans+=n-i+1;
				}
				cout<<ans<<"\n";
			}
		}
		
	}
	return 0;
} 

