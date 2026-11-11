#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5;
int n, m, a[N], ans[M], s[M];
vector<int> v;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i ++){
		scanf("%d", &a[i]);
	}
	for(int i = 1;i <= n;i ++){
		memset(s, 0, sizeof(s));
		v.clear();
		v.push_back(-1);
		for(int j = i;j <= n;j ++){
			if(s[a[j]] != 0){
				int k = v.size() - 1;
				while(k > s[a[j]]){
					s[v[k]] = 0;
					v.pop_back();
					k --;
				}
				v.push_back(a[j]);
				s[a[j]] = v.size() - 1;
			}
			else{
				v.push_back(a[j]);
				s[a[j]] = v.size() - 1;
			}
		}
		for(int i = 1;i <= m;i ++){
			if(s[i] != 0){
				ans[i] ++;
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		printf("%d ", ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}