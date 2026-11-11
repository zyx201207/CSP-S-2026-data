#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int h=0;
	int maxx=-1;
	int ccc,ddd;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxx){
			maxx=a[i]&a[j];ccc=i,ddd=j;}
		}
	}
	a[ccc]=0,a[ddd]=0;
	h=maxx;
	for(int i=3;i<=m;i++){
		int maxn=-1;
		int flag=0;
		for(int j=1;j<=n;j++){
			if(h&a[j]>maxn){
				maxn=h&a[j];
				flag=j;
			}
		}
		h=maxn;
		a[flag]=0;
	}
	cout<<h;
	return 0;
}

