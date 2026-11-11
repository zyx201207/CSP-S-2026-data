#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int now=0;
	for(int i=29;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++) if((a[j]&now)==now&&(a[j]&(1<<i))==(1<<i)) sum++;
		if(sum>=m) now|=(1<<i);
	}
	printf("%d\n",now);
	return 0;
}