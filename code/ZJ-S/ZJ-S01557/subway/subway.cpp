#include<bits/stdc++.h>
using namespace std;
struct sub{
	int xa,ya;
}a[10001];
int c,n,m,d,q,w[10001],k,minn,f=1;
void dfs(int x,int y,int sum){
	if(x==y){
		if(f){
			minn=sum;
			f=0;
		}else minn=min(minn,sum);
		return;
	}
	for(int i=0;i<n;i++)if(a[i].xa==x)dfs(a[i].ya,y,sum+w[x]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k>>a[i].xa>>a[i].ya;
	}
	while(q--){
		int xx,yy,sum=0;
		cin>>xx>>yy;
		dfs(xx,yy,sum);
		cout<<minn<<endl;
	}
	return 0;
}
