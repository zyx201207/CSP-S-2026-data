#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200006];
int mx=-2e9;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int sum,int st,int last){
	//cout<<sum<<endl;
	if(st>=m){
		mx=max(mx,sum);
		return;
	}
	for(int i=last+1;i<=n-m+1+st;i++){
		int x;
		if(st==0){
			x=a[i];
		}
		else{
			x=sum&a[i];
		}
		if(x>mx) dfs(x,st+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(0,0,0);
	cout<<mx;
	return 0;
}
