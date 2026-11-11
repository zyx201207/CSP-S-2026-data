#include <bits/stdc++.h> 
using namespace std;

int n,m;
int a[500001];
int s[300001];
int ans[300001];
int q[300001];
int id[300001];
int sum = 0;
int t = 0;

int solve(){
	for(int i = 1;i <= 300000;i++){
		if(s[i] > 1) return 0;
	}
	return 1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		s[s[i]]++;
	}
	for(int i = 1;i <= m;i++){
		ans[i] = n;
	}
	for(int l = 1;l <= n;l++){
		for(int i = 1;i <= n;i++){
			if(q[a[i]] == 1 && a[i] != 0){
				for(int j = id[a[i]];j < i;j++){
					q[a[j]] = 0;
					s[a[j]]--;
					a[j] = 0;
				}
			}
			q[a[i]] = 1;
			id[a[i]] = i;
			if(solve() == 1){
				break;
			}
		}
		for(int i = 1;i <= m;i++){
			if(q[i] == 0) ans[i]--;
		}
		for(int i = 1;i <= m;i++){
			q[i] = 0;
			id[i] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
