#include<bits/stdc++.h>
using namespace std;
long long a[50005],sum;
int main(){
	int n;
	cin>>n;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long r=1,m=n;
		while(r<=m){
			long long mid=(r+m)>>1;
			if(f(mid)){
				sum=mid;
				r=mid+1;
			}
		}
		cout<<r;
	}
	reaturn 0;
} 
