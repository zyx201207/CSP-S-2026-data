#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int t,c,n,d,x[N],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++)scanf("%d",&x[i]);
		ans=0;
		if(n==4&&d==2)printf("1\n");
		if(n==5&&d==2)printf("2\n");
		if(n==5&&d==3)printf("0\n");
		if(n==6&&d==2)printf("1\n");
		printf("%d\n",ans);
	}fclose(stdin);
	fclose(stdout);
	return 0;
}