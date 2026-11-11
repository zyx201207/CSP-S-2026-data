#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N];
long long m; 
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n >>m;//
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool fl=1;
	long long c=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=c)fl=0;
	} 
	if(fl){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum>m){
				cout<<i;
				return 0;
			}
		} 
		if(sum<m){
			cout<<n;
			return 0;
		}
	}
	sort(a+1,a+1+n);
	long long sum=2;
	while(1){
		sum++;
		for(int i=1;i<sum;i++){ 
			long long t=(a[sum]-a[i]);
			if((m-t)<0){
				cout<<sum-1;
				return 0;
			}
			a[i]+=t;
			m-=t;
		}
		if(sum>=n){
			break;
		}
		if(m<0){
			cout<<sum;
			return 0;
		}
	}
	cout<<n;
	return 0;
}