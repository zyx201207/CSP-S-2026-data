#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=0,sum=0;
	
	for(int i=n-1;i>=0;i--){
		int r=i,mm=m;
		while(r>=0){
			if((a[i]-a[r])<=mm){
				mm-=(a[i]-a[r]);
				sum++;
			}
			r--;
		}
		ans=max(ans,sum);
		sum=0;
	}
	cout<<ans;
	return 0;
}
