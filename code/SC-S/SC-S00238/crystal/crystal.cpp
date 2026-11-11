#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long n,m,a[N],ans;
bool flag=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1])flag=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])flag2=0;
	}
	if(flag){
		cout<<n;
		return 0;
	}
	if(flag2){
		int sum1=0,k=abs(a[n]-a[n-1]);
		for(int i=1;i<=n;i++){
			sum1+=(i*k);
			if(sum1>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long cnt=1,cnt2=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>cnt2){
				ans=max(ans,cnt);
				break;
			}
			cnt2=cnt2-a[i]+a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}