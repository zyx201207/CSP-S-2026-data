#include<bits/stdc++.h>
using namespace std;
int a[500005],pos[500005],c[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,cnt;
	bool A = true;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] > a[i+1]&&i != n){
			A = false;
		}
	}
	if(A){
		for(int i = 1;i <= n;i++){
			memset(pos,0,sizeof(pos));
			cnt = 0;
			for(int j = i;j <= n;j++){
				if(pos[a[j]]){
					cnt = pos[a[j]]-1;
				}
				c[++cnt] = a[j];
				pos[a[j]] = cnt;
			}
			for(int j = 1;j <= cnt;j++){
				ans[c[j]]++;
			}
		}
		for(int i = 1;i <= m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		memset(pos,0,sizeof(pos));
		cnt = 0;
		for(int j = i;j <= n;j++){
			if(pos[a[j]]){
				for(int k = pos[a[j]]+1;k <= cnt;k++){
					pos[c[k]] = 0;
				}
				cnt = pos[a[j]]-1;
			}
			c[++cnt] = a[j];
			pos[a[j]] = cnt;
		}
		for(int j = 1;j <= cnt;j++){
			ans[c[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
