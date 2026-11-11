#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e6+5;
int c,t,ans,ans1,ans2;
int n,d;
void dfs(int x,int y);
int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll a[MAXN];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dfs(i,j);
			}
		}
		cout<<ans;
		ans=0;
	}
}
void dfs(int x,int y){
	  
}