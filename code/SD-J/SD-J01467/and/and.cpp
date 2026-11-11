#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m;
long long a[N];
//void zhuan(long long x,long long i){
//	long long now=1,cnt=0,sum=0;
//	while(now<=x){
//		now*=2;
//		cnt++;
//	}
//	sum=cnt;
//	while(x!=0){
//		long long xx=x;
//		x/=2;
//		if(xx%2==1){
//			c[i][cnt]='1';
//		}
//		else{
//			c[i][cnt]='0';
//		}
//		cnt--;
//	}
////	for(int j=1;j<=sum;j++){
////		cout<<c[i][j];
////	}
////	cout<<"\n";
//}
bool cmp(long long x,long long y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//zhuan(a[i],i);
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans<<"\n";
	return 0;
} 
