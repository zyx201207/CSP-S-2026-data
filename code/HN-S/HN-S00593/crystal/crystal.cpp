#include<bits/stdc++.h>
using namespace std;
long long n,a[5000005],m,ans=1,c,sum[5000005],k=1,f,g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	if(f==0){
		f=1;
		for(int i=2;i<=500000;i++){
			if(f>m){
				cout<<i-1;
				return 0;
			}
			f+=i;
		}
	}
	f=0;
	g=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=g){
			f=1;
		}
	}
	if(f==0){
		f=g;
		for(int i=2;i<=500000;i++){
			if(f>m){
				cout<<i-1;
				return 0;
			}
			f+=i*g;
		}
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=2;i<=n;i++){
		if(sum[i]<=m){
			ans=i;
		}else{
			break;
		}
	}
	for(int i=ans+2;i<=n;i++){
		if(sum[i]>m){
			k++;
			for(int j=1;j<=k-1;j++){
				sum[i]-=a[i]-a[j];
				if(sum[i]<=m){
					ans=i-j;
				}
			} 
		}
	}
	cout<<ans;
	return 0;
} 
