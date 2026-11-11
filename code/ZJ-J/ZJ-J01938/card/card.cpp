#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long lst[3000010],a[5000100],cnt[3000010],ans[3000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		lst[a[i]] = i;
		cnt[a[i]]++;
	}
	for(int i = 1;i <= n;i++){
		int k = i - 1;
		while(k != n){
			k++;
			k = lst[a[k]];
			ans[a[k]] ++;
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

