#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int book[2005][2005];
int f(int x,int l){
	if(book[x][l]!=-1) return book[x][l];
	if(x==1&&l==1) return book[x][l]=a[1];
	if(l<x) return book[x][l]=-3546325;
	return book[x][l]=max(f(x-1,l-1)&a[l],f(x,l-1));
}
bool check(){
	int l=0,r=(1<<20);
	for(int i=1;i<=n;i++){
		bool k=0;
		while(l<=r){
			int mid=(l+r)/2;
			int now=(1<<mid)-1;
			if(a[i]==now){
				k=1;
				break;
			}else if(a[i]<=now){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(!k){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout << mx;
	}else if(m==n){
		int res=a[1];
		for(int i=2;i<=n;i++){
			res&=a[i];
		}
		cout << res;
	}else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout << mx;
	}else if(n<=2000){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				book[i][j]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			book[1][i]=max(book[1][i-1],a[i]);
		}
		cout << f(m,n);
	}else if(check()){
		int mx=1000000001;
		for(int i=1;i<=n;i++){
			mx=min(mx,a[i]);
		}
		cout << mx;
	}else{
		cout << a[n];
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/

