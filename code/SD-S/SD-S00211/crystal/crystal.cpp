#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N] ;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mx=0;
	for(long long i=n;i>=1;i--){
		long long y=a[i];
		long long sum=0,cnt=0;
		for(long long j=i;j>=1;j--){
			sum+=y-a[j];
			cnt++;
			if(sum<=m){
				mx=max(mx,cnt);
			}else{
				break;
			} 
		}
	}
	cout<<mx;
	return 0;
} 
