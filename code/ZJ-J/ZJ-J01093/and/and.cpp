#include<bits/stdc++.h>
#define fri freopen("and.in","r",stdin)
#define fro freopen("and.out","w",stdout)
#define con const int
#define endl '\n'
#define intl long long
using namespace std;
con  N=2e5+5;
int a[N];
bool vis[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	intl ans=0;
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((a[i]>>k&1) && vis[i]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans|=(1<<k);
			for(int i=1;i<=n;i++){
				if((a[i]>>k&1) && vis[i]){
					continue;
				}
				vis[i]=0;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	fri;fro;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

