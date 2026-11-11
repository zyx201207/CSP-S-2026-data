#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[1000005],ans,ma,f1=1,f1_,f2,sum[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=30;j++){
			if(pow(2,j)-1==a[i]){
				f1_=1;
				break;
			}
		}
		if(f1_!=1) f1=0;
	}
	if(f1){
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		cout<<a[m];
	}
	//sort(a+1,a+1+n);
	else if(n<2000){
		for(int i=1;i<=n-m+1;i++){
			for(int j=i+m;j<=n+1;j++){
				ans=a[i];
				for(int k=i+1;k<=j-1;k++){
					ans&=a[k];
				}
				ma=max(ma,ans);
			}
			
		}
		cout<<ma;
	}
	else{
		sum[1]=a[1];
		sum[2]=a[1]&a[2];
		for(int i=3;i<=n;i++){
			sum[i]=sum[i-1]&a[i];
		}
		for(int i=1;i<=n-m+1;i++){
			ma=max(ma,sum[i-1]&sum[i+m-1]);
		}
		cout<<ma;
	}
	return 0;
}
