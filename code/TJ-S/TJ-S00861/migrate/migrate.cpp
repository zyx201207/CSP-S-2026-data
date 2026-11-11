#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,sum,ans,m;
	scanf("%d%d",&n,&d);
	int a[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<d){
			if(a[i+1]-a[i-1]<d){
				i++;
				sum++;
			}
		}
	}
	if(sum>=n+3){
		ans++;
	}
	printf("%d",max(sum,ans));
	return 0;
}
