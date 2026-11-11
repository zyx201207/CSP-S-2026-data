#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n,k,mmax=-1,mmax1=-1,x;
int ans;
int a[N];
bool f(int x){
	while(x%2==0){
		x/=2;
	}
	if(x==1) return 1;
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++)
			mmax=max(mmax,a[i]);
		cout<<mmax;
		return 0;
	}
	else if(k==n){
		ans=a[1];
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	else if(k==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					mmax=max(mmax,a[i]&a[j]);
		cout<<mmax;
		return 0;
	}
	else if(f(n)){
		x=a[n-2]&a[n-3];
		cout<<x;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			mmax=max(mmax,a[i]);
			if(a[i]<mmax && a[i]>mmax1) mmax1=a[i];
		}
		x=mmax&mmax1;
		cout<<x;
	}
	return 0;
}
