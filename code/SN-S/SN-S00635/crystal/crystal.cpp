#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,maxx,gc,tr[500005];bool flag=1;
long long dc(long long a[]){
	for(int i=1;i<n;i++){
		if(abs(a[i]-a[i+1])!=gc) flag=0;
	}
	return flag;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);gc=a[n]-a[n-1];
	if(dc(a)){
		for(int i=1;i<=n;i++)
			tr[i+1]=tr[i]+i*gc;
		for(int i=2;i<=n+1;i++){
			if(m<tr[i]){
				cout<<i-1;
				return 0;
			}
			if(m>=tr[i]&&i==n){
				cout<<n;
				return 0;
			}
		}
	}
	for(int i=n;i>1;i--){
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j]; 
			if(sum>m){
				if(i-j>maxx){
					maxx=i-j;
				}
				break;
			}
			else if(sum<=m&&j==1){
				if(i-j+1>maxx){
					maxx=i-j+1;
				}
				break;
			}
		}
		sum=0;
	}
cout<<maxx;
	return 0;
} 
