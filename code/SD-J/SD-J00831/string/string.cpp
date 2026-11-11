#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const long long N=2*100000+10;
long long a[N];
long long f1[N],f2[N];
char c[N];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		f1[i]=f2[i]=a[i];
	}
	long long l=1,r=n;
	long long ans=0;
	long long k1=n/2;
	long long k2;
	if(n%2==0){
		k2=n/2;
	}
	else{
		k2=n/2+1;
	}
	while(l<=n&&r>=1){
		if(c[l]==c[r]){
			long long t=min(f1[l],f2[r]);
			f2[r]-=t;
			f1[l]-=t;
			if(f2[r]==0) r--;
			if(f1[l]==0) l++;
		}
		else{
			long long t=min(f1[l],f2[r]);
			ans+=t;
			f2[r]-=t;
			f1[l]-=t;
			if(f2[r]==0) r--;
			if(f1[l]==0) l++;
		}
	}
	cout<<ans/2;
	return 0;
}

