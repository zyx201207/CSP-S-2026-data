#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long arr[N],crr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		crr[i]=crr[i-1]+arr[i];
		if(arr[i]!=arr[i-1]){
			f=1;
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(f==0){
		cout<<n;
		return 0;
	}
	sort(arr+1,arr+n+1);
	long long sum=0,x=1;
	for(long long i=2;i<=n;i++){
		if((crr[x]+m)>=(x*arr[i])){
			x++;
			sum=x;
		}
	}
	cout<<sum;
	return 0;
}

