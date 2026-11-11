#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[500005];

int w[500005];

int dp[100000005];

bool cmp(int a,int b){
	return a > b;
}

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	bool specialA = true;
	bool specialB = true;
	int cha;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i){
			specialA = false;
		}
		
		if(i == 2){
			cha = a[i]-a[i-1];
		}
		if(i>=3){
			if(a[i]-a[i-1] != cha){
				specialB = false;
			}
		}
	}
	
	if(specialA){
		int i=1;
		int ans = 0;
		while(m>=0){
			m-=i;
			ans++;
			i++;
		}
		cout << ans;
		return 0;
	}
	
	if(specialB){
		int ans = 0;
		while(m>=0){
			m -= cha;
			ans++;
			cha *= 2;
		}
		cout << ans;
		return 0;
	}
	
	sort(a+1,a+1+n,cmp);
	
	int ans = -1;
	
	for(int i=1;i<n;i++){
		memset(w,0,sizeof(w));
		for(int j=i+1;j<=n;j++){
			w[j] = a[i]-a[j];
		}
/*		
		for(int q=1;q<=n;q++){
			cout << w[q] << " ";
		}
		
		cout << "\n";
*/
	
		for(int j=i+1;j<=n;j++){
			for(int k=m;k>=w[j];k--){
				dp[k] = max(dp[k],dp[k-w[j]]+1);
			}
		}
		
		ans = max(dp[m],ans);
	}
/*	
	int ans = -1;
	
	for(int i=1;i<n;i++){
		
		int cnt = 0;
		
		int j = i+1;
		
		int cost = 0;
		
		int cur_m = m;
		
		while(cur_m-cost >= 0){
			
			cost = a[i]-a[j];
			cur_m -= cost;
			
			cnt++;
			
			j++;
			

		}
		
		ans = max(ans,cnt);
	}
*/	
	cout << ans;
	
	return 0;
}
