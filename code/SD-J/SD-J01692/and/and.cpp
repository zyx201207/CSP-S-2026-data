#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans,h,j;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,greater<int>());
	ans = a[1];
	for(int i = 2;i <= m;i++){
		ans = ans & a[i];
	}
	printf("%d",ans);
	return 0;
}
