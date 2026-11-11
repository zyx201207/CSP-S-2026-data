#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500001];
int mx,b1,b[500001];
void dfs(int x,int s){
	//cout<<x<<' '<<s<<'\n';
	if(x>n){
		mx=0;b1=1;
		for(int i=1;i<=n;i++)b[i]=a[i];
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			if(b[i]==b[i-1]){
				b1++;
			}else{
				b1=1;
			}
			mx=max(mx,b1);
		}
		ans=max(ans,mx);
		return;
	}
	for(int i=0;i<=s;i++){
		a[x]+=i;
		dfs(x+1,s-i);
		a[x]-=i;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,m);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
