#include<bits/stdc++.h>
using namespace std;
long long n,a[1234567890];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long b[10000000],c[10090000],sum=0,ans=0,d[100000];
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
			b[i]=a[i]%(a[i]/2);
			sum++;
		}
		for(int j=sum;j>=1;j--){
			c[ans++]=b[j];
		}
		for(int j=1;j<=ans;j++)
			c[i]+=b[j]*10;
		sum=0;
		ans=0;
	}

	for(int i=1;i<=n;i++){
		d[i]=c[i]%10&&c[i+1]%10;
		c[i]-=c[i]%10/10;
		c[i+1]-=c[i+1]%10/10;
		ans++;
	}
	for(int i=1;i<=ans;i++){
		cout<<d[i];
	}
	return 0;
}
