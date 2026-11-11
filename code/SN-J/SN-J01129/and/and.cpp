#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int n,k,ans;
void dfs(int p,long long sum){
	if(p>=k){
		if(sum>ans) ans=sum;
		return;
	}
	for(int i=p;i<=n;i++){
		b[p]=a[i];
		dfs(p+1,sum&=a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	memset(b,0x3f,sizeof b); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,2147483647);
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

*/

