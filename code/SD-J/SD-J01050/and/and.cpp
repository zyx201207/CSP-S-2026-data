#include<bits/stdc++.h>
using namespace std;
int n,m;
long long er[22]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152};
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long fff=a[n];
	for(int i=n-1;i>=n-m+1;i++){
		fff&=a[i];
	}cout<<fff;
	return 0;
}
