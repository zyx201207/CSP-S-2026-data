#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[100005];
int df(int x,int y){
	int sn=a[x];
	for(int i=x+1;i<=y;i++){
		sn=sn&a[i];
	}
	return sn;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen(" and.in","r",stdin);
	freopen(" and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=df(1,m);
	cout<<ans;
	return 0;
}
