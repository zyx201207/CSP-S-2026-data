#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,i,j;
long long ans;
long long a[200005];
int sum[40];
int foil(long long x){
	for(j=0;x>0;j++){
		sum[j]=(x%2)&sum[j];
		x/=2;
	}
	maxn=max(j,maxn);
	return 0;
}
int Foil(long long x){
	for(j=0;x>0;j++){
		sum[j]=x%2;
		x/=2;
	}
	maxn=max(j,maxn);
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	Foil(a[i-1]);
	for(i=n-1;i>n-m;i--){
		foil(a[i]);
	}
	for(i=0;i<=maxn;i++){
		if(sum[i]==1)ans+=(pow(2,i));
	}
	cout<<ans;
	return 0;
} 
