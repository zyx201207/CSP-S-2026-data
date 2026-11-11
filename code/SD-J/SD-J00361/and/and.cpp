#include<bits/stdc++.h>
#define N 200050
using namespace std;
int n,m,a[N],ans=(1<<30)-1,cnt;
int Log2 (int x){
	return 31-__builtin_clz (x);
}
bool cmp (int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		cnt=max (cnt,Log2 (a[i]));
	}
	for (int mk=cnt; mk>=0; mk--){
		sort (a+1,a+1+n,cmp);
		if (a[m]>>mk){
			for (int i=1; i<=m; i++){
				ans&=a[i];
			}
			cout<<ans;
			return 0;
		}
		int p=1<<mk;
		for (int i=1; a[i]>>mk; i++){
			a[i]-=p;
		}
	}
	cout<<0;
	return 0;
}
