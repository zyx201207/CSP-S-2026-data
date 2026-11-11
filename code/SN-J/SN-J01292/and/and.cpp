#include<bits/stdc++.h>
using namespace std;
int n,m,mx;
int a[200010];
void dfs(int x,int f,int d){
	if(d==m){
		mx=max(mx,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=f){
			dfs(x&a[i],a[i],d++);
		}
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
//dfs(a[1],1,1);
//cout<<mx;
if(m==n){
	int v=a[1];
	for(int i=1;i<=n;i++){
		v=v&a[i];
	}
	cout<<v;
}
	else if(m==1){
		int v=0;
		for(int i=1;i<=n;i++){
			v=max(v,a[i]);
		}
		cout<<v;
	}
	else if(m==2){
	
	int v=0;
	for(int i=1;i<=n;i++){
		v=max(v,a[i-1]);
		cout<<v;
	}
}
	return 0;
} 
/*
3
2 a
2 b
1 c
*/
