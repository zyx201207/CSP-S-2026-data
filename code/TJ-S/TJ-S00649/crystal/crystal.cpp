#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000005],ma,l,k,f,g,sum;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	g=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=g) f=1;
	}
	if(f){
		l=m;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			m=l;
			k=0;
			for(int j=i-1;j>=1;j--){
				if(m>0&&a[i]-a[j]<=m){
					m-=(a[i]-a[j]);
					k++;
				}
			}
			ma=max(ma,k);
		}
		if(ma==0) cout<<0;
		else cout<<ma+1;
	}
	else{
		while(m>=0){
			sum++;
			m-=(g*sum);
			if(sum==n&&m>0){
				cout<<n;
				return 0;
			}
		}
		cout<<sum;
	}
	return 0;
} 
