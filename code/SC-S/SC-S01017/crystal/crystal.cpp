#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],dp[20010][20010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int c;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[j][i]=a[i]-a[j];
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int sum=0,t=1;
		for(int j=i-1;j>=1;j--){
			sum+=dp[j][i];
			t++;
			if(sum>m){
				t--;
				break;
			}
		}
		mx=max(mx,t);
	}
	cout<<mx;
	return 0;
}