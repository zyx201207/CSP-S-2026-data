#include<bits/stdc++.h>
using namespace std;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
int n,d,cnt,res,a[2000005];
void dfs(int x,int end,int k){
	if(x==end){
		if(k==res) cnt++;
		else if(k<res){
			cnt=1;
			res=k;
		}
		return;
	}
	for(int i=x+1;i<=end;i++){
		if(a[i]-a[x]>d) return;
		else dfs(i,end,k+1); 
	}
	return;
}
bool solve(int u,int v){
	res=INT_MAX;
	cnt=0;
	dfs(u,v,0);
	if(cnt==2) return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(solve(i,j)){
					ans++;
					//cout<<i<<" "<<j<<endl;
				}
				//cout<<i<<" "<<j<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
