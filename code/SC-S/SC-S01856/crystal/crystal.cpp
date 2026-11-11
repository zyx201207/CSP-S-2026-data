#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int afat[500010],dt[500010],axi[500010],ii[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		afat[i]=a[i];
	}
	sort(afat+1,afat+n+1);
	int aw=0;
	for(int i=1;i<=n;i++){
		dt[i]=afat[i]-afat[i-1];
		for(int j=0;j<=i;j++){
			aw=axi[i]+dt[i-j]+axi[i];
			if(aw>=n)break;
			ii[i]++;
			axi[i]=aw;
		}
	}
	sort(ii+1,ii+n+1,greater<int>());
	printf("%d",ii[1]+1);
    return 0;
}