#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x,mx,_mx,vis[200005],flag,_f;
void dfs(int dp,int xx){
	if(dp==m+1){
		_mx=max(_mx,xx);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(dp+1,xx&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	x=a[1];
	_f=1;
	mx=a[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		x=x&a[i];
		mx=max(mx,a[i]);
		if(a[i]!=a[i-1]+1){
			_f=0;
		}
	}
	if(m==n){
		cout<<x;
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(_f){
		if(m>n/2){
			cout<<0;
			return 0;
		}
		if(m==n/2){
			cout<<m;
			return 0;
		}
		if(m<=n/4){
			cout<<n-m;
			return 0;
		}
		cout<<n/2;
		return 0;
	}
	if(m==n-1){
		_mx=-1;
		for(int i=1;i<=n;i++){
			_mx=max(_mx,(a[i]&x));
		}
		cout<<_mx;
		return 0;
	}
	if(m==2){
		_mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				_mx=max(_mx,(a[i]&a[j]));
			}
		}
		cout<<_mx;
		return 0;
	}
	_mx=-1;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(2,a[i]);
		vis[i]=0;
	}
	cout<<_mx;
	return 0;	
}
