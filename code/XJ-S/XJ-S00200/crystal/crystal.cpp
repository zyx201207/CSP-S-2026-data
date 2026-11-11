#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,shu=1;cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		for(long long j=i;j>1;j--){
			if(a[j]<a[j-1]){
				long long h=a[j];
				a[j]=a[j-1];
				a[j-1]=h;
			}
		}
	}
	long long x;
	if(n%2==0){
		x=n/2;
	}
	else{
		x=n/2+1;
	}
	long long d=1,e=1;
	for(long long i=1;i<=n;i++){
		if(0-(a[x+d-1]-a[x+d])<a[x-e+1]-a[x-e]){
			c[i]=a[x+d-1]-a[x+d];
			d++;
			continue;
		}
		else{
			c[i]=a[x-e+1]-a[x-e];
			e++;
			continue;
		}
	}
//	if(b[1]==b[2]&&b[2]==b[3]){
//		cout<<m/b[1];
//		return 0;
//	}
	int sum=0;
	for(long long i=1;i<n;i++){
		long long f=0;
		f+=c[i];
		m-=f;
		if(m>=0){
			sum++;
		}
		else{
			break;
		}
	}
	cout<<sum;
	return 0;
}
