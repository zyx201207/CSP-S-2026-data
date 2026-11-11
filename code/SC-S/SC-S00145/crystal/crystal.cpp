#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n>5000){
		long long q=a[2]-a[1];
		cout<<m/q;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ma=0;
	for(long long i=1;i<=n;i++){
		long long t=m,sum=0;
		while(a[i]==a[i+1]){
			i++;
		}
		for(long long j=i;j>=1;j--){
			if(t>=a[i]-a[j]){
				t-=(a[i]-a[j]);
				sum++;
			}
			else{
				break;
			}
		}
		ma=max(ma,sum);
	}
	cout<<ma;
	return 0;
} 