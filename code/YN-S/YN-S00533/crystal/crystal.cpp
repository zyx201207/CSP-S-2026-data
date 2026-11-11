#include<bits/stdc++.h>
using namespace std;
const int N=5e+5;
long long n,m;
long long a[N],b[N];
long long f=-N;
bool check(int x){
	long long v=a[x]*x-b[x];
	if(v<=m)return 1;
	else return 0;
}
bool cnt(){
	int d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=d)return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
//	cout<<cnt()<<"\n";
	if(cnt()==0){
		for(long long r=1;r<=n;r++){
			for(long long l=1;l<=r;l++){
				long long v=a[r]*(r-l+1)-b[r]+b[l]-1;
				if(v<=m)
					f=max(f,r-l+1);
			}
		}
		cout<<f<<"\n";
	}else {
		long long l=1,r=n,mid=(l+r)/2;
		while(l<r){
			mid=(l+r)/2;
			if(check(mid)){
				l=mid;
			}else {
				r=mid;
			}
			if(r-l==1){
//				cout<<l<<" "<<r<<" "<<a[mid]*mid-b[mid]<<"\n";
				r=l;
			}
		}
		cout<<l<<"\n";
	}
	return 0;
}
