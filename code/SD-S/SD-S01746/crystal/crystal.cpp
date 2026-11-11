#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crysral.out","w",stdout);
	cin>>n>>m;
	c[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[i]+c[i-1];
	}long long int l=1,r=0,sum=-1;
	while(l<=n){
		long long int x=c[l]-c[r];
		long long int y=a[l]*l-a[l]*r;
		if(x+m>=y){
			sum=max(sum,l-r);
			l++;
		}else{
			r++;
		}if(l==r){
			l++,r--;
		}
	}cout<<sum;
	return 0;
}

