#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
int t[8000][8000];
int j[250005];
int a[500005],b[500005];
int l,r,minlen=2147483647,tt;
int f[250005];
void dfs(int now,int len){
	if(now==r){
		minlen=min(minlen,len);
		return;
	}
	for(int i=1;i<=m;i++){
		if(f[i]==0&&t[now][i]==1){
			f[i]=1;
			dfs(i,len+1);
			f[i]=0; 
		}
	}
}
int zhy(){
	minlen=2147483647;
	cin>>l>>r;
	dfs(l,0);
	cout<<minlen*2*tt+j[l]+j[r]<<"\n";
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>j[i];
	}
	for(int i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int sum;
		cin>>sum;
		for(int i=1;i<=sum;i++){
			cin>>a[i]>>b[i];
			tt=b[i];
		}
		for(int i=1;i<=sum;i++){
			for(int j=1;j<=sum;j++){
				if(i!=j){
					t[a[i]][a[j]]=1;
				}
			}
		}
	}
	while(q--){
		zhy();
	}
	return 0;
} 
