#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],c[500005],cnt,now,maxn;
signed main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	c[n]=s[n]=0;
	for(int i=n-1;i>=1;i--){
		c[i]=a[i+1]-a[i];
		s[i]=s[i+1]+c[i];
	}
	now=n;
	cnt=1;
	maxn=-1;
	for(int i=n;i>=1;i--){
		if(i!=n){
			cnt--;
			m+=cnt*(s[i]-s[i+1]);			
		}
		while(m-(s[now-1]-s[i])>=0){
			if(now==1) break;
			now--;
			m-=s[now]-s[i];
			cnt++;
			if(now==1) break;
		}
		maxn=max(maxn,cnt);
	}
	cout << maxn;
	return 0;
} 
