#include<bits/stdc++.h>
using namespace std;

const int N=500010;
long long a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	
	long long sum=m;
	long long num=0;
	long long ma=-0x3f3f3f;
	
	if(n<=500010){
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			sum=m;
			num=0;
			for(int j=i-1;j>=1;j--){
				if(i!=j){
					if((a[i]-a[j])<=sum){
						sum-=(a[i]-a[j]);
						num++;
					}else{
						break;
					}
				}
			}
		ma=max(ma,num);
		}
		cout<<ma+1;
	}else{
		for(int i=n;i>=1;i--){
			sum=m;
			num=0;
			for(int j=i-1;j>=1;j--){
				if(i!=j){
					if((a[i]-a[j])<=sum){
						sum-=(a[i]-a[j]);
						num++;
					}else{
						break;
					}
				}
			}
		ma=max(ma,num);
		}
		cout<<ma+1;
	}
	
	


	return 0;
}
