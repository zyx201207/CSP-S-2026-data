#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> a,f;
int ans[300010],an[300010];
int x;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&x);
		a.push_back(x);
		f.push_back(x);
	}
	for(int i = 0;i <= n;i++){
		memset(an,sizeof(an),0);
		for(int u = 1;u <= n;u++){
			a[u] = f[u];
		}
		for(int j = i+1;j <= n;j++){
			for(int k = i;k <= j;k++){
				if(a[k] = j){
					for(int t = k;t <= n;t++){
						a[t] = 0;
					}
				}
			}
			a.push_back(j);
		}
		for(int j = 1;j <= n;j++){
			if(an[a[j]] = 1) continue;
			else{
				an[a[j]] = 1;
				ans[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;

}
