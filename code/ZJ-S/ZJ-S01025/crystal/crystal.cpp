#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
bool p=1;
long long m,a[N],mn=1e15,x=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n-1;i++){
		if (a[i+1]-a[i]<m)
			p=0;
	}
	if (p==1) {
		printf("%d",1);
		return 0;
	}
	while ((1+x)*x/2<=m&&x<=n){
		x++;
	}
	long long ned=(n-1)*n/2;
	if (ned<m)
		printf("%lld",x-1);
	else 
		printf("%lld",x);
	return 0;
}