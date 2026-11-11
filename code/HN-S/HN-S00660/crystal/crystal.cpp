#include<bits/stdc++.h>
using namespace std;
long long n=0,cnt=1,sum=0;
long long m=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=1;i--){
		cnt=1;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]<=m){
				m=m-a[i]+a[j];
				cnt++;
				if(sum<cnt){
					sum=cnt;
				}
				continue;
			}else{
				cnt++;
				if(sum<cnt){
					sum=cnt;
				}
				cnt=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
