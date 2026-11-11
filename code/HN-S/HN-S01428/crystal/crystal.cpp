#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
bool cmp(int x,int y){
	int xx=x,yy=y;
	if(x<0) xx=-x;
	if(y<0)	yy=-y;
	return xx<yy;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
//	long long zs_shu=0,zs=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	
	long long zys=a[n/2+1];
	long long lj=m,ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==zys){
			if(a[i+1]!=zys){
				zys=i;
				break;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	
	for(long long i=1;i<=zys;i++){
		lj+=a[i];
		long long pjs=lj/i,as=i;
		for(long long j=1;j<=n;j++){
			if(a[j]==pjs){
				if(j>i){
					as++;
				}
			}
		}
		if(as>ans && as!=0){
			ans=as;
		}
	}
	cout<<ans;

	
	return 0;
}
