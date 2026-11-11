#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans=0;
bool cmp(int x,int y){
	return x>y;
}
void ff(int i,int yong,int mu){
	if(mu<ans){
		return ;
	}
	if(yong==m){
		ans=mu;
		return ;
	}
	if(i>n){
		return ;
	}
	if(yong+n-i+1<m){
		return ;
	}
	ff(i+1,yong+1,mu&a[i]);
	ff(i+1,yong,mu);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ff(1,0,INT_MAX);
	cout<<ans;
	return 0;
}