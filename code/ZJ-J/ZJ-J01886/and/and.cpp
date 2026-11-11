#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans,maxn;
int dp[2005][2005]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)	cin >> a[i],maxn = max(a[i],n);
	if(n<=2000){
		for(int i = 1,j = 0;i<=n;i++){
			if(a[i]>j)	j = a[i];
			dp[i][1] = j;
		}
		for(int i = 2;i<=n;i++){
			for(int j = 2;j<=n && j<=m;j++){
				for(int k = 1;k<=i;k++){
					for(int l = k+1;l<=i;l++){
						dp[i][j] = max(dp[i][j],max(dp[k][j-1]&a[l],dp[k][j]));
					}
				}
			}
		}
		for(int i = 1;i<=n;i++)	ans = max(ans,dp[i][m]);
		cout << ans << '\n';
		return 0;
	}else if(maxn<4){
		sort(a+1,a+1+n,cmp);
		int sum0,sum1,sum2,sum3;
		for(int i = 1;i<=n;i++){
			if(a[i] == 0)	sum0++;
			else if(a[i] == 1)	sum1++;
			else if(a[i] == 2)	sum2++;
			else sum3++;
		}
		if(sum3>=m)	cout << 3;
		else if(sum3+sum2>=m)	cout << 2;
		else if(sum3+sum1>=m)	cout << 1;
		else cout << 0;
		return 0;
	}else{
		sort(a+1,a+1+n,cmp);
		int ans = a[1];
		for(int i = 2;i<=m;i++)	ans&=a[i];
		cout << ans << '\n';
		return 0;
	}
	return 0;
}
