#include <bits/stdc++.h>
using namespace std;

long long a[200005];
long long arr[200005];
int b[31]={
	1,2,4,8,16,32,64,128,256,512,1024,2048,4096,
	8192,16384,32768,65536,131072,262144,524288,
	1048576,2097152,4194304,8388608,16777216,
	33554432,67108864,134217728,268435456,536870912
};

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	int l=n;
	long long ans=0;
	for (int i=29;i>=0;i--){
		int c=0;
		for (int j=1;j<=l;j++){
			if (a[j]>=b[i]){
				c++;
				a[j]-=b[i];
				arr[c] = a[j];
			}
		}
		if (c>=m){
			ans += b[i];
			l=c;
			for (int j=1;j<=l;j++){
				a[j] = arr[j];
			}
		}
	}
	
	cout << ans;
	
	return 0;
}