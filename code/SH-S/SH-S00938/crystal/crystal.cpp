#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010];
void solve1(){
	for(int i=1;i<=n;i++){
		long long sum=m;
		int cnt=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=sum){
				cnt++;
				sum-=a[i]-a[j];
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000) solve1();
	else{
		long long tmp=0;bool op=1;
		for(int i=1;i<=n;i++){
			tmp+=a[n]-a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]) op=0;
			}
		}
		if(tmp<=m){
			cout<<n;
			return 0;
		}
		if(op){
			tmp=a[2]-a[1];
			cout<<m/tmp;
		}
	}
	return 0;
}
