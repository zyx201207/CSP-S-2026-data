#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long cost,date;
};
long long n,m,k,x,y,ans;
long long a[500010];
long long b[500010];
long long c[500010];
Node dp[500010];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	c[2]=a[2]-a[1];
	for(int i=3;i<=n;i++){
		c[i]=(i-1)*a[i]-(b[i-1]);
	} 
	for(int i=1;i<=n;i++){
    	if(m-dp[i-1].cost-c[i]>=0){
    		if(i!=1) c[i+1]=(i-1)*(a[i+1]-a[i]);
    		dp[i].date=dp[i-1].date+1;
    		dp[i].cost=dp[i-1].cost+c[i];
		}else{
		    dp[i].date=dp[i-1].date;
			dp[i].cost=dp[i-1].cost;	
		}
	}
	cout<<dp[n].date;
	return 0;
} 
