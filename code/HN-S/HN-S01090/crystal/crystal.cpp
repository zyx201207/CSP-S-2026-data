#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans,mx;
long long m,a[N];
struct S{
	long long son;
	int far;
}b[N];
long long c(S z,S x){
	return z.son<x.son;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){	
		for(int i=n;i>=1;i--){
			long long mm=m;
			int f=0;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=m)ans++,m=m-a[i]+a[j];
				else{
					f=1;
					break;
				}
			}
			if(!f){
				cout<<ans+1;
				return 0;
			}
			mx=max(mx,ans+1);
		}
		cout<<mx;
	}else{
		long long sum=(a[1]+a[n-1])*(n-1)/2;
		if(sum-m<=0)b[n].son=sum-m;
		else b[n].son=-1e18;
		b[n].far=n;
		for(int i=n-1,j=1;i>=1;i--,j++){
			if(sum-m-a[j]<=0)b[i].son=sum-m-a[j];
			else b[i].son=-1e18;
			b[i].far=i;
			sum-=a[j];
		}
		b[1].son=-1e18+1;
		sort(b+1,b+1+n,c);
		cout<<b[n].far;
	}	
	return 0;
}
