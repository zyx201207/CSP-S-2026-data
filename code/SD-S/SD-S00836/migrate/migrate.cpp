#include<bits/stdc++.h>
using namespace std;
struct island{
	int zheng;
	int yu;
}dp[1000000];
bool check(island a,island b){
	if(b.zheng==a.zheng+1&&b.yu<a.yu) return true;
	else if(b.zheng==a.zheng) return true;
}
int n,c,t,flag,a[1000000],ans;
long long d;
int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		ans=0;
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i].zheng=a[i]/d;
			dp[i].yu=a[i]%d;
		}
		for(int j=2;j<=n;j++){
		flag=0;
		for(int i=j+1;i<n;i++){
			if(check(dp[i-1],dp[i])){
			if(dp[i].zheng==dp[i-1].zheng) flag=1;
			if (flag){
				flag=0;
				if(check(dp[i],dp[i+1])&&(dp[i+1].zheng>dp[i].zheng))ans++;
				flag=0;
				}
			}
			else{
				j=i+1;
				break;
			}
		}
	}	
	cout<<ans<<endl; 
		}
	
	return 0;
} 
