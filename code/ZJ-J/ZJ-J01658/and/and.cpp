#include<bits/stdc++.h>
using namespace std;
int n,m;
long long res;
long long a[200005];
void dfs(int dep,int pos,long long now){
	if(dep>m){
		res=max(res,now);
		return;
	}
	if(pos>n){
		return;
	}
	dfs(dep,pos+1,now);
	dfs(dep+1,pos+1,now&a[pos]);
}
bool cmp(int a,int b){
	return a>b;
}
bool flag=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag>=4){
			flag=false;
		}
	}
	if(n==m){
		res=a[1];
		for(int i=2;i<=n;i++){
			res&=a[i];
		}
		cout<<res;
		return 0;
	}
	if(flag){
		sort(a+1,a+n+1,cmp);
		res=a[1];
		for(int i=2;i<=m;i++){
			res&=a[i];
		}
		cout<<res;
		return 0;
	}
	if(n>2500){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	} 
	dfs(1,1,(1ll<<31)-1);
	cout<<res;
	return 0;
} 
