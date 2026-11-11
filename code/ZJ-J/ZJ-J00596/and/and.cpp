#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5*2+100,M=100;
int a[N],n,m,num[N][M],dp[M],ans;
void deal(int sum,int x){
	int cnt=0;
	while(sum){
		num[x][cnt]=sum%2;
		sum/=2;
		cnt++;
	}
	return ;
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		deal(a[i],i);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=35;j++){
			dp[j]+=num[i][j];
		}
	}
	for(int i=m;i<=n;i++){
		for(int j=0;j<=35;j++){
			dp[j]-=num[i-m][j];
		}
		int sum=0;
		for(int j=0,base=1;j<=35;j++){
			if(dp[j]>=m)
			sum+=base;
			base*=2;
		}
		ans=max(ans,sum);
		for(int j=0;j<=35;j++){
			dp[j]+=num[i+1][j];
		}
	}
	cout<<ans;
}
