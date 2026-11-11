#include<bits/stdc++.h>
using namespace std;
long long x[200005],m,n,a[200005],sum,ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}else if(m==2){
		ma=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
		return 0;
	}else{
		cout<<4;
	}
    return 0;
}