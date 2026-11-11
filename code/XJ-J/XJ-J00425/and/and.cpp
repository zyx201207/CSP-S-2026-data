#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+5;
LL n,m,ans,a[N],mx,vis[N];
void f(int k,int sum){
	if(k>m){
		if(sum>mx) mx=sum;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			f(k+1,sum&a[i]);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		f(2,a[i]);
		vis[i]=0;
	}
	cout<<mx;
	return 0;
}