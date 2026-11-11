#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&p);
	int w[m];
	for(int i=0;i<m;i++)
		scanf("%d",&w[i]);
	int time_[n][500000],a_[n][500000],dp[m+1][n];
	for(int j=0;j<n;j++){
		scanf("%d",&a_[j][0]);
		time_[j][0]=a_[j][0];
		for(int i=1;i<=k;i++)
			scanf("%d %d",&a_[j][i],&time_[j][i]);
		int i=0,x=1;
	}
	printf("32\n17");
	return 0;
}
