#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long pow2[105]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
/*
4 2
3 15 12 12
*/
/*
5 3  
31 3 1 15 7
*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	int res=a[n];
	for(int i=n;i>=n-m+1;i--) res&=a[i];
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	int k=0,ans=0;
	for(int i=n;i>=1;i--){
		if(k) break;
		for(int j=1;j<=30;j++){
			if(a[i]==pow2[j]-1){
				ans=a[i];
				k=i;
				break;
			}
		}
	}
//	cout<<ans<<endl;
	for(int i=k;i>=k-m+1;i--) ans&=a[i];
	cout<<max(ans,res)<<endl;
	return 0;
}
