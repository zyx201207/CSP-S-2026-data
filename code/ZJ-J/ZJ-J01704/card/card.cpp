#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int lst[M];
long long cnt[N];
int a[N], vis2[M], vis1[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i <= n; i++){	
		for(int j = i; j <= n; j++)vis1[a[j]] = 0, vis2[j] = 0, lst[a[j]] = n;
		for(int j = i; j <= n; j++){
			if(vis1[a[j]] && !vis2[lst[a[j]]]){
				for(int k = lst[a[j]]; k < j; k++){
					vis2[k] = 1;
				}
				lst[a[j]] = j;
			}
			else{
				vis1[a[j]] = 1;
				lst[a[j]] = j;
				//cout << j << endl;
			}
		}
		for(int j = i; j <= n; j++){
			//cout << vis2[j] <<' ';
			if(!vis2[j])cnt[a[j]]++;
		}
		//cout << endl;
	
	}
	for(int i = 1; i <= m; i++)
		printf("%lld ", cnt[i]);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

only ten min
i'm excited
i love ccf very much
100 + 100 + 50 + 48 = 298
maybe 1=

*/
