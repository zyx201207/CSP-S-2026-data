//过了样例123 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	//卡A
	if(n<=500005&&a[n-1]==n&&a[n-2]==n-1){
		cout<<max(1,min(signed(n),signed(sqrt(2*m+0.25)+0.5)));
		return 0;
	} 
	//卡B
	if(n<=500005&&2*a[n-2]==a[n-1]+a[n-3]){
		int d=a[n-1]-a[n-2],a0=a[0]-d;
		int _a[n];
		if(d<0){
			for(int i=0;i<n;i++)_a[i]=a[n-i];
			for(int i=0;i<n;i++)a[i]=_a[i];
			d=-1*d;
		}
		cout<<max((long long)1,min((long long)(n),(long long)(sqrt(2.0*m/(d*1.0)+0.25)+0.5)));
		return 0;
	} 

	
	//先做O(n*n)
	int tmp=m,ans[n];
	for(int i=0;i<n;i++)ans[i]=0;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		tmp=m;
		for(int j=i;j>=0;j--){
			if(tmp-(a[i]-a[j])>=0){
				tmp-=(a[i]-a[j]);
				ans[i]++;
			}
		}
	}
	//for(int i=0;i<n;i++)cout<<ans[i]<<' ';
	cout<<ans[max_element(ans,ans+n)-ans];
	//O(n*n)没有问题
	return 0;
}
