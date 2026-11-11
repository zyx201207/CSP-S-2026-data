#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char c;
}a[200010];
int n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].x,&a[i].c);
	}
	int l=1,r=n;
	while(l<r){
		int minx=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c)sum+=minx;
		a[l].x-=minx,a[r].x-=minx;
		if(a[l].x<1)l++;
		if(a[r].x<1)r--;
	}
	printf("%lld",sum);
	return 0;
}