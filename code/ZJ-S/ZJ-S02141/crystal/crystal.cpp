//Oct31==Dec25?
//T1 crystal 解法2 预期75
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],maxn=-1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=0;
	}
	if(n==1){//特判n=1时
		cout<<1;
		return 0;
	}else if(n==2){//特判n=2时
		if(max(a[1],a[2])-min(a[1],a[2])<=m) cout<<2;
		else cout<<1;
		return 0;
	}
	if(f2){//针对13到18测试点
		for(int i=1;i<=n;i++){
			if(m>=i)m-=(i*(a[2]-a[1]));
			else{
				cout<<i;
				return 0;
			}
		}
	}
	//以下是暴力
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){//以a[i]为能量值时的水晶最大数
		int M=m,ans=1;
		for(int j=i-1;j&&M;j--){
			if(M>=(a[i]-a[j])){
				M-=(a[i]-a[j]);
				ans++;
			}else break;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}