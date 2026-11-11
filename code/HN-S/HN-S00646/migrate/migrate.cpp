#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long w[2000005][2000005];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		long long d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					w[i][j]=1;
				}
			}
		}
	}
	return 0;
}
