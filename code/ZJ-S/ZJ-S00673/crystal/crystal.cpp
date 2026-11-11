#include<bits/stdc++.h>
using namespace std;
long long a[500010];
typedef unsigned long long ull;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;
	cin>>n>>m;
	int o=0,f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			continue;
		}
		if(i==2){
			o=a[i]-a[i-1];
		}else{
			if(a[i]-a[i-1]!=o){
				f=1;
			}
		}
	}
	sort(a+1,a+n+1);
	ull ans=0;
	if(n<=5000){
		ull mx=0;
		for(ull j=1;j<=n;j++){
			ans=0;
			for(ull i=j+1;i<=n;i++){
				ans+=(a[i]-a[i-1])*(i-j);
				if(ans>m){
					mx=max(mx,i-j);
					break;
				}
			}
			if(ans<=m)mx=max(n-j+1,mx);
		}
		cout<<mx<<endl;	
	}else if(f==0){
		for(int i=2;i<=n;i++){
			ans+=(a[i]-a[i-1])*(i-1);
			if(ans>m){
				cout<<i-1;
				break;
			}
		}
		if(ans<=m){
			cout<<n;
		}
	}else{
		cout<<n;
	}
	return 0;
}
