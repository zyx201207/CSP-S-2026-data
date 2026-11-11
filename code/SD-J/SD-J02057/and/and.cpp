#include<iostream>
using namespace std;

int k,m,a[200005];

int ans=0;
int dfs(int x,int y,int t,int cnt){
	if(y==1){
		if(t==0)t=a[x];
		else t=t&a[x];
	}
	if(cnt==m){
		ans=max(ans,t);
	}
	if(x<=k)dfs(x+1,0,t,cnt);
	if(x<=k)dfs(x+1,1,t,cnt+1);
	return 0;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>k>>m;
	int ma=-2147483647;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(k==m){
		int op=a[1];
		for(int i=2;i<=k;i++){
			op=op&a[i];
		}
		cout<<op;
		return 0;
	}if(m==2){
		int ooop=-2147483647;
		for(int i=1;i<=k;i++){
			for(int j=i;j<=k;j++){
				if(i==j)continue;
				ooop=max(ooop,a[i]&a[j]);
			}
		}
		cout<<ooop;
		return 0;
	}
	if(k>20)k=20;
	dfs(1,0,0,0);
	dfs(1,1,0,1);
	cout<<ans;
	return 0;
}
