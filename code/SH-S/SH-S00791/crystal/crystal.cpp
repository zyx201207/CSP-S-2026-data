#include<bits/stdc++.h>
using namespace std;
//const long long N=500005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[90005],qzc,max1=1,upt[90005];
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i=1;i<=n;i++){
//		long long j=0,tmp=m,scr=1;
//		while(m>=0){
//			m-=(a[j+1]-a[j])*scr;
//			if(m<0) break;
//			a[j]=a[j+1];
//			j++;scr++;
//		}
//		if(scr>max1){
//			max1=scr;
//			//cout<<j<<endl;
//		}
//	}
	upt[0]=0;
	for(long long i=1;i<n;i++){
		upt[i]=(a[i]-a[i-1])*i+upt[i-1];
	}
//	for(int i=1;i<n;i++){
//		cout<<upt[i]<<endl;
//	}
	long long i=0,j=1;
	while(j<n){
		while(upt[j]-upt[i]<=m&&j<n) j++;
		max1=j-i;
		while(upt[j]-upt[i]>m&&j<n){
			i++;j++;
		}
	}
	cout<<max1;
	return 0;
}
