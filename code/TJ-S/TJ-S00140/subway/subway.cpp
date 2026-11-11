#include <bits/stdc++.h>r
using namespace std;
long long a[1000000],b[1000000],c[1000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m,ans=1,cnt=0;
	cin >>n >>m;
	if(m==0 or n==1){
		cout <<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		c[i]+=c[i-1];
	}
	for(int i=2;i<=n-1;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+cnt;j<=n;j++){
			if(b[j]-b[i-1]-(c[j]-c[i-1])*(i-1)<=m){
				cnt++;
			}
			else break;
		}
	}
	cout <<cnt-1;
	return 0;
} 
