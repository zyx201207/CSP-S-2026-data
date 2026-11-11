#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=-1e9,a[N];

void solve1(){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=0,sum=m;
		for(int j=i;j>0;j--){
			if(sum>=(a[i]-a[j])){
				sum=sum-a[i]+a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}

void solve2(){
	int cnt=0;
	for(int i=n;i>0;i--){
		if(m>=(a[n]-a[i])){
			m=m-a[n]+a[i];
			cnt++;
		}
	}
	cout<<cnt;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000) solve1();
	else solve2();
	return 0;
}
