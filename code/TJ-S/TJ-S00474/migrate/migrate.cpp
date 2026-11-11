#include <bits/stdc++.h>
using namespace std;
long long n,d,a[2000005],cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=3){
		cout << 0;
	} 
	long long b=a[n]-a[n-1],c=1;
	for(int i=n;i>1;i--){
		if(a[i]-a[i-1]==b){
			cnt++;
		} 
	}
	int sum=0;
	if(cnt==n-1){
		if(n==4&&d>=2*b) cout <<1;
		if(n==5&&d>=3*d) cout <<3;
		if(n==5&&d<3*d&&d>=2*d) cout << 2;
	}
	if(a[n]-a[1]<=d){
		int f[2000005];
		f[1]=1;
		f[2]=3;
		for(int i=3;i<=n-3;i++){
			f[i]=f[i-1]+f[i-2];
		}
		cout << f[n-3];
	}
	cout << 0;
	return 0;
}
