#include <bits/stdc++.h>
using namespace std;
int n,m,num,d,ans;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 1;i<=m;i++){
		scanf("%d",&num);
		scanf("%d",&d);
		ans = 0;
		for(int j = 1;j<=num;j++)scanf("%d",&a[j]);
		for(int j = 1;j<num-d;j++){
			if((num-j)%d==0)ans+=n-1;
			else ans+=(num-j)%d;
		}
		printf("%d",ans);
		cout<<endl;
	}
	return 0;
}
