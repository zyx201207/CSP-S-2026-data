#include<bits/stdc++.h>
using namespace std;
int main() {
	//114514 debate 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int c,f,d,n,m;
	scanf("%d %d",&n,&m);
	int a[n+2],b[n+2];
	for(int i=0 ; i<n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	printf("%d",a[n-m]);
	return 0;
}
