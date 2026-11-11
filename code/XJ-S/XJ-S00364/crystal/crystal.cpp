#include <bits/stdc++.h>
using namespace std;
int n,maxx;
int m;
const int N=2e8+10;
int a[10100],b[10010];
int zx=N,zd;
bool pd(int mid){
	int sum=0;
	int shen=m;
	int gs=0; 
	for(int i=1;i<=n;i++){
		b[i]=mid-a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]>=0&&shen>0){
			shen-=b[i];
			gs++;
		}
	}
	return m-shen;
} 
int pd1(int mid){
	int sum=0;
	int shen=m;
	int gs=0; 
	for(int i=1;i<=n;i++){
		b[i]=mid-a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]>=0&&shen>0){
			shen-=b[i];
			gs++;
		}
	}
	return gs;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
		zx=min(zx,a[i]); 
	}
	sort(a+1,a+n+1);
	int l=zx,r=zd;
	int mid=0;
	int xb=0;
	while(l<=r){
		mid=(l+r)/2;
		if(pd(mid)<=m){
			l=mid+1;
			xb++;
			maxx=max(maxx,pd1(l));
		}else{
			r=mid-1;
		}
	}
	cout<<maxx;
	return 0;
}
