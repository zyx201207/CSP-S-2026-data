#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],dp[500010];
/*bool check(long long x){
	int y=upper_bound(a+1,a+n+1,x)-a;
	long long m1=m,cnt=0,cnt2=0;
	for(int i=1;i<=min(n,y);i++){
		if(x<a[i]){
			break;
		}
		if(m1>=abs(x-a[i])){
			m1-=abs(x-a[i]);
			cnt++;
		}else{
			break;
		}
	}
	if(ans<cnt){
		ans=cnt;
		return 1;
	}
	return 0;
}*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
		//cout<<dp[i]<<" ";
	}
	int x=upper_bound(dp+1,dp+n+1,m)-dp;
	cout<<x-1<<" "<<endl;
	return 0;
}
