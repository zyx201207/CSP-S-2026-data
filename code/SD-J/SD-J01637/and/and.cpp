#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxx=0,maxa=0;
int n,m;
int a[200001];
void dfs(int id,int sum,int c){
	if(c==0)
	maxx=max(maxx,sum);
	if(id>n||c<0)return;	
	if(sum==0&&c==m){
		dfs(id+1,a[id],c-1);
		dfs(id+1,0,c);
	}
	else{
		dfs(id+1,sum&a[id],c-1);
		dfs(id+1,sum,c);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	} 
	dfs(1,0,m);
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
