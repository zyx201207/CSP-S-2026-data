#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)    cin>>a[i];
	sort(a+1,a+n+1);
	bool f=true;
	long long k=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=k)    f=false;
	}
	if(f){
		long long sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			sum+=i*k;
			cnt++;
			if(sum>m)    break;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			if(sum+a[i]-a[j]<=m){
				sum+=a[i]-a[j];
				cnt++;
			}
			else    break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
