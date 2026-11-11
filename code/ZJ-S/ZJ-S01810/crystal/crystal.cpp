#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ma=-1;
	for(int i=2;i<=n;i++){
		long long f=m;
		int g=i;
		long long sum=1;
		while(a[g]==a[g+1]){
			g++;
			sum++;
		}
		for(int j=i-1;j>=1;j--){
			if(f<a[i]-a[j]){
				break;
			}
			else{
				f=f-a[i]+a[j];
				sum++;
			}
		}
		ma=max(ma,sum);
	}
	cout<<ma;
	return 0;
}













