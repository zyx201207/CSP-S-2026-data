#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long i=n,j=n,ans=0;
	while(i!=1){
		if(m>=a[j]-a[i-1]){
			m-=(a[j]-a[i-1]);
			i--;
		}else{
			while(m<a[j]-a[i-1]){
				m+=(a[j]-a[j-1])*(j-i);
				j--;
			}
			m-=(a[j]-a[i-1]);
			i--;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
