#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid,ans=1;
long long m,a[500005],b[500005];
int xxx(int x){
	int f=0;
	long long num1,num2;
	for(int i=x;i<=n;i++){
		num1=a[i]*x;
		num2=b[i]-b[i-x];
		if(num1-num2<=m){
			f=1;
			break;
		}
	}
	return f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	l=1;
	r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(xxx(mid)==1){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
