#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,maxn=-1;
int a[N];
int b[N][40];
int c[40];
bool f[N];
bool fx[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m+1;i--){
		if(i==n) maxn=a[i];
		else maxn=maxn&a[i];
	}
	printf("%d",maxn);
	return 0;
}
