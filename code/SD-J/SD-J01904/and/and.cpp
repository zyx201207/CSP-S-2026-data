#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int a[N],andd[N];
bool f[N];
int n,k,max_and=-1,s=0;

void dfs(int x){
	if(x == k+1){
		for(int i=1;i<=k;i++){
			if(i==1) s=andd[a[1]] & andd[a[2]];
			else if(i==2) continue;
			else s=s & andd[a[i]];
		}
		max_and=max(max_and,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=true;
			a[x]=i;
			dfs(x+1);
			f[i]=false;
		} 
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>andd[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			max_and=max(max_and,andd[i]);
		}
	}else if(m==n){
		for(int i=1;i<=m;i++){
			if(i==1) s=andd[1] & andd[2];
			else if(i==2) continue;
			else s=s & andd[i];
		}
		max_and=max(max_and,s);
	}else{
		dfs(1);
	}
	
	cout<<max_and;
	return 0;
}
