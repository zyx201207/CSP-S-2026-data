#include<bits/stdc++.h>
using namespace std;
long long dp[10005][10005];
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=a[j]-a[i];
		}
	}
	int maxx=0;
	for(int j=2;j<=n;j++){
		int c=0,x=m;
		for(int i=1;i<=j-1;i++){
			if(x-dp[i][j]>=0){
				x-=dp[i][j];
				c++;
			}
		}
		maxx=max(maxx,c);
	}
	cout<<maxx+1;
	fclose(stdin);
	return 0;
}