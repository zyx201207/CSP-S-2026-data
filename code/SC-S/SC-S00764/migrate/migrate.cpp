#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c,t,n,m,ans;
struct node{
	ll mn,sum,v;
}a[5010];
void dfs(ll v,ll bs){
	if(v > n){
		return;
	}
	if(bs < a[v].mn){
		a[v].mn=bs;
		a[v].sum=1;
	}else if(bs == a[v].mn){
		a[v].sum++;
	}
//	ll add = 0;
	for(int i = 1;i+v <= n && a[i+v].v-a[v].v<=m;i++){
		dfs(i+v,bs+a[i+v].v-a[v].v);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int iii = 1;iii <= t;iii++){
		cin >> n >> m;
		ans=0;
		for(int i = 1;i <= n;i++){
			a[i].v = 0;
			a[i].mn = 0x3fffffffffff;
			a[i].sum = 0;
		}          
		for(int i = 1;i <= n;i++){
			cin >> a[i].v;
		}
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
//				a[i].v = 0;
				a[j].mn = 0x3fffffffffff;
				a[j].sum = 0;
			}          
			dfs(i,0);
//			cout<<i<<":\n";
			for(int j = i;j <= n;j++){
//				cout<<a[j].sum<<"<---"<<j<<endl;
				if(a[j].sum-1 == 2){
					ans++;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 