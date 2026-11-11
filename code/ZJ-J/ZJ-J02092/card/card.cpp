#include<bits/stdc++.h>
#define N 500005
typedef long long ll;
using namespace std;

int n,m;
int a[N];
int cnt[N];
int l[N];
int ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
		a[i] = x;
		l[x] = i;
	}
	for(int i = 1 ; i <= m ;i++){
		int p = l[i];
		int tmp = 0;
		for(int j = p ; j <= n ; j++){
			j = l[a[j]];
			ans[a[j]] += cnt[i];
		}
	}
	for(int i = 1 ; i <= m ; i++){
		printf("%d ",ans[i]);
	}

	return 0;
}
