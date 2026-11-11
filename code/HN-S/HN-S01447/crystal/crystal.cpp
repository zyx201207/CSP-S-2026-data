#include<bits/stdc++.h>
using namespace std;
bool rd(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int mmax=-999,a[500005],sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,rd);
	for(int i=2;i<=n;i++){
		sum=1;
		int mm=m;
		for(int j=i-1;j>=1;j--){
			mm=mm+a[j]-a[i];
			if(mm<0){
				break;
			}
			sum++;
		}
		if(sum>=mmax){
			mmax=sum;
		}
	}
	cout<<mmax;
	return 0;
}
