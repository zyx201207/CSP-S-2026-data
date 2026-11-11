#include<bits/stdc++.h>
using namespace std;
long long a[500005];
struct abc{
	long long b,c;
};
abc x[12497505];
bool cmp1(long long y,long long z){
	return y>z;
}
bool cmp2(abc y,abc z){
	if(y.c!=z.c){
		return y.c>z.c;
	}
	return y.b<z.b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp1);
	for(int i=0;i<n-1;i++){
		long long h=0,k=1;
		for(int j=i+1;j<n;j++){
			h+=a[i]-a[j];
			k++;
			x[sum].b=h;
			x[sum].c=k;
			sum++;
		}
	}
	sort(x,x+sum,cmp2);
	if(x[0].b<=m){
		cout<<x[0].c;
		return 0;
	}
	for(long long i=1;i<sum;i++){
		if(x[i-1].b>m&&x[i].b<=m){
			cout<<x[i].c;
			return 0;
		}
	}
	
} 
