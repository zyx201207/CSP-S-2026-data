#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int a[5000005],n,m;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0,ans=1,maxn=0,l=1;
	for(int i=2;i<=n;i++){
		int tt=(a[i]-a[i-1])*(i-l);
		if(m-sum>=tt){
			sum+=tt;
			ans++;
			maxn=max(maxn,ans);
		}else{
			while(m-sum<tt&&l<i-1) sum-=(a[i]-a[l]),l++,ans--;
			if(m-sum<tt) break;
			sum+=tt;
			ans++;
			maxn=max(maxn,ans);
		}
	}
	cout<<maxn;
	return 0;
	
} 
