#include<bits/stdc++.h>
using namespace std;
long long int arr[5000005],n,m,s,ma=1,l=2,mm;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	while(l<=n){
		mm=m;
		for(long long int i=l;i<=n;i++){
			if((arr[i]-arr[i-1])*(i-l+1)<=mm){
				mm-=(arr[i]-arr[i-1])*(i+1-l);
			}else{
				s=i-l+1;
				break;
			}
			if(i==n){
				cout<<n;
				return 0;
			}
		}
		l++;
		if(ma<s)ma=s;
	}
	cout<<ma;
	return 0;
}
