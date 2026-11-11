#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	
	int a[n+5]={0}; // 1 base
	bool aFlag=true, bFlag=true; // 是否满足A / B 
	
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(i!=a[i]) aFlag=false;
	}
	
	sort(a+1,a+n+1);
	
	long long d=0;
	
	for(int i=1;i<=n;i++) {
		if (i==2) {
			d=a[i]-a[i-1];
		}
		if(i>2 && bFlag) {
			int t=a[i]-a[i-1];
			if(d!=t) {
				bFlag=false;
			}
		}
	}
	
	int ans=1;
	if(n==1) {
		ans=1;
	}
	else if(n==2) {
		if(m>=(a[2]-a[1])) ans = 2;
		else ans = 1;
	}
	else if (aFlag) {
		if(n==2) {
			if(m>=1) ans = 2;
			else ans = 1;
		}
		else {
			int b=n;  //选取基数
			long long tmp=m;
			int idx=n-1;
			while(tmp>0) {
				if (tmp-(b-idx)>=0) {
					ans+=1;
					tmp-=(b-idx);
					if(idx>1) idx--;
					else break;
				}
				else break;
			}
		}
	}
	else if (bFlag) {
		if(n==2) {
			if(m>=d) ans = 2;
			else ans = 1;
		}
		else {
			int b=a[n];  //选取基数
			long long tmp=m;
			int idx=n-1;
			while(tmp>0) {
				if (tmp-(b-a[idx])>=0) {
					ans+=1;
					tmp-=(b-a[idx]);
					if(idx>1) idx--;
					else break;
				}
				else break;
			}
		}
	}
	else {
		//暴力 
		for(int i=n;i>=1;i--) {
			//if (ans>i) break;
			int ans_tmp=1;
			int b=a[i];
			long long tmp=m;
			int idx=i-1;
			while(tmp>0) {
				if (tmp-(b-a[idx])>=0) {
					ans_tmp+=1;
					tmp-=(b-a[idx]);
					if(idx>1) idx--;
					else break;
				}
				else break;
			}
			ans=max(ans, ans_tmp);
		}
	} 
	
	cout << ans;
	
	return 0;
}
