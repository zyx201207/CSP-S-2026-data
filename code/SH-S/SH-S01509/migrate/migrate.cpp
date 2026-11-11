#include <bits/stdc++.h>
using namespace std;
long long islands[2000005];
bool exist(int i,int a,long long* islands,long long d){
	int ans = 0;
	for (int j = i + 1;j < i + a;j++){
		if (islands[j] - islands[i] <= d && islands[i + a] - islands[j] <= d)
			ans += 1;
	}
	return ans == 2;
}
int search(long long* islands,int n,long long d){
	int ans = 0;
	for (int i = 0;i < n;i++){
		int a = 0;
		for (int j = i + 1;j < n;j++){
			if (islands[j] - islands[i] <= 2 * d){
				a += 1;
				if (islands[j] - islands[i] > d && exist(i,a,islands,d))
					ans += 1;
			}
			else{
				break;
			}
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while (t--){
		int n;
		long long d;
		scanf("%d %lld",&n,&d);
		for (int i = 0;i < n;i++)
			scanf("%lld",&islands[i]);
		printf("%d\n",search(islands,n,d));
	}
	return 0;
}
