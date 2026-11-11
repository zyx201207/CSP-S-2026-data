#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int ans=0;
bool vis[200005];
void dfs(int cnt,int now){
	if(now<ans) return;
	if(cnt==m){
		ans=max(ans,now);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(cnt+1,(now&a[i]));
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);//freopen("and.in","w",stdout);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i]+1;
		while(1){
			if(k!=1&&(k&1)==1){
				A=false;
				break;
			}
			else{
				if(k==1) break;
				else k>>=1;
			}
		}
	}
	if(A){
		sort(a+1,a+n+1,cmp);
		int sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	} 
	dfs(0,2147483647);
	cout<<ans;
	return 0;
}

