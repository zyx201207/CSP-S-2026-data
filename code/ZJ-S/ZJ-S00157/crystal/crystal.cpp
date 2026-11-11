#include<bits/stdc++.h>
using namespace std;
long long a[1145141];
long long b[1145141]={0,0};
int main(){
	long long n,m,sum=0,cm,ans=-10000;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n>114514){
		cout<<n;
	}
	else{
		sort(a+1,a+n+1);
	//	for(int i = 2;i<=n;i++){
	//		b[i]=b[i-1] + (a[i]-a[i-1])*(i-1);
	//	}
		for(long long i = 2;i<=n;i++){
			sum=1;
			cm=m;
			for(long long j = i-1;j>=1;j--){
				if(a[i]-a[j] <= cm){
					sum++;
					cm-=(a[i]-a[j]);
				}
			}
			//cout<<sum<<endl;
			ans=max(ans,sum);
			if(sum == n){
				break;
			}
		}
		cout<<ans<<endl;
	//	for(int i = n;i<=1;i--){
	//		for(int i = 1)
	//	}
	}
	return 0;
}