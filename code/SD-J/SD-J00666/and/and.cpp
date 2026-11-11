#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],p[200005]={0},maxx=0;
void dfs(long long x,int y,int cnt){
	if(y==m){
		maxx=max(maxx,x);
		return;
	}
	if(cnt>n)return;
	dfs(x,y,cnt+1);
	if(x=0)x=a[y+1];
	dfs(x&a[y+1],y+1,cnt+1);
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	p[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]&a[i];
	}
	if(m=1){
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}
	if(m=n){
		cout<<p[n];
		return 0;
	}
	dfs(0,0,1);
	cout<<1 and 1;
	return 0;
} 
