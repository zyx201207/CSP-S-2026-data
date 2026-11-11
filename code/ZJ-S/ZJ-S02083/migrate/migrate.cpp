#include<bits/stdc++.h>
using namespace std;

const int N = 2000010;
int testid,t,n,ans;
long long d;
long long a[N];
long long buc[N],minn = -1;

void dfs(int curu,int tot,int tar){
	if(curu == tar){
		buc[tot]++;
		if(minn != -1 && minn < tot){
			buc[tot] = 0;
			return;
		}
		if(minn == -1 || minn > tot){
			buc[minn] = 0;
			minn = tot;
			return;
		}
	}
	if(minn != -1 && minn < tot) return;
	for(int i = curu + 1; i <= n; i++){
		if((a[i] - a[curu]) > d){
			break;
		}
		dfs(i,tot+1,tar);
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> testid >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				minn = -1;
				dfs(i,1,j);
				if(buc[minn] == 2) ans++;
				buc[minn] = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}