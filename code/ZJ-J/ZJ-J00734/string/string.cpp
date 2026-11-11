#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		sum1[i]=sum1[i-1]+a[i];
	}
//	for(int i=n;i>=1;i--){
//		sum2[i]=sum2[i+1]+a[i];
//	}
	long long cnt=0;
//	long long l=1,r=1;
//	long long cnt=0,twt=sum1[n]/2;
	int idl=1,idr=n;
//	int ti=0;
	while(idl<idr){
//		cerr<<idl<<" "<<idr<<"\n";
		long long minn=min(a[idl],a[idr]);
		if(c[idl]!=c[idr]){
			cnt+=minn;
		}
		a[idl]-=minn;
		a[idr]-=minn;
		if(a[idl]==0)idl++;
		if(a[idr]==0)idr--;
//		ti++;
//		if(ti==10)break;
	}
//	cout<<cnt;
	cout<<cnt;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/