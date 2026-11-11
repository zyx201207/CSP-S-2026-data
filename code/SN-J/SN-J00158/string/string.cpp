#include<bits/stdc++.h>
using namespace std;
long long n,l,r,m;
struct qwe{
	long long x;
	char y;
}q[1000005];
void dfs(long long a,long long b){
	if(b<=a){
		return ;
	}
	if(q[a].x==q[b].x){
		if(q[a].y==q[b].y){
			dfs(a+1,b-1);
		}else{
			m+=q[a].x;
			dfs(a+1,b-1);
		}
	}else if(q[a].x>q[b].x){
		if(q[a].y==q[b].y){
			q[a].x-=q[b].x;
			dfs(a,b-1);
		}else{
			q[a].x-=q[b].x;
			m+=q[b].x;
			dfs(a,b-1);
		}
	}else{
		if(q[a].y==q[b].y){
			q[b].x-=q[a].x;
			dfs(a+1,b);
		}else{
			q[b].x-=q[a].x;
			m+=q[a].x;
			dfs(a+1,b);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].x>>q[i].y;
	}
	l=1;
	r=n;
	if(n==1){
		cout<<0;
		return 0;
	}
	dfs(l,r);
	cout<<m;
	return 0;
}

