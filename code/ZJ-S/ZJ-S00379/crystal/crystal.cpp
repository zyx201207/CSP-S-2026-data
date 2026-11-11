#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[500005];
long long sum3[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		long long cnt=a[2]-a[1];
		for(int i=2;i<=n;i++){
			sum3[i]=sum3[i-1]+cnt*(i-1);
			if(sum3[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		long long cnt=0;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
//			cout<<i<<" "<<j<<" "<<a[i]-a[j]<<endl;
			if(sum>m){
				cnt=j;
				break;
			}
		}
		ans=max(ans,i-cnt);
	}
	cout<<ans;
	return 0;
}