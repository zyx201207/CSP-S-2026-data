#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200005];
void f(int x,int k,int cnt){
	if(k!=0&&cnt<=ans)return;
	if(k==m){
		ans=max(ans,cnt);
		return;
	}
	if(x>n)return;
	if(k==0)f(x+1,k+1,a[x]);
	else f(x+1,k+1,(cnt&a[x]));
	f(x+1,k,cnt);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	f(1,0,0);
	cout<<ans;
	return 0;
}
