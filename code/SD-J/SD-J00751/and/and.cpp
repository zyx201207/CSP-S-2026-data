#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	printf("%d",sum);
	return 0;
} 
