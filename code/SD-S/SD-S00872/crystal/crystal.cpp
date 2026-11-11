#include<bits/stdc++.h>
using namespace std;
long long n,a[100100],sum;
long long m;
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[2]-a[1];
	bool t=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=sum){
			t=0;
			break;
		}
	}
	if(t){
		if(sum==0){
			cout<<n;
			return 0; 
		}
		cout<<m/sum+1;
		return 0;
	}//AB
	for(int i=n;i>=2;i--){
		a[i]=a[i]-a[i-1];
	}//²î 
	sum=0;
	long long ans=1,ans1=1,sum1=0,j=2;
	for(int i=2;i<=n;i++){
		sum+=abs(a[i])*ans1;
		sum1+=abs(a[i]);
		ans1++;
		while(sum>m){
			sum-=sum1-abs(a[j]);
			sum1-=abs(a[j]);
			j++;
			ans1--;
			if(ans1<=0){
				ans1=1;
			}
		}
		ans=max(ans1,ans);
	}
	cout<<ans;
	return 0;
} 
