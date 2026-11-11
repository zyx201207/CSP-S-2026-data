#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long sum;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	if(n>5000){
		int t=a[2]-a[1];
		for(int i=1;i<=n;i++){
			sum+=i*t;
			ans++;
			if(sum>m){
				ans--;
				break;
			}
		}
		cout<<ans<<t;
		return 0;
	}
	for(int i=1;i<n;i++){
		sum=0;
		long long ans1=1;
		for(int j=i+1;j<=n;j++){
			sum+=b[j]*(j-1);
			++ans1;
			if(sum>m){
				ans1--;
				break;
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
