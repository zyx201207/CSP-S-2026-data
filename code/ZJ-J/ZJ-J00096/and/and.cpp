#include <bits/stdc++.h>
using namespace std;

int a[20001],n,m;
int f(int v,int m){
	int mx=0;
	if(m==0){
		return v;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=-1){
			int o=a[i];
			a[i]=-1;
			mx=max(mx,f(o&v,m-1));
			a[i]=o;
		}
	}
	return mx;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int o=a[i];
		a[i]=-1;
		mx=max(mx,f(o,m-1));
		a[i]=o;
	}
	cout << mx;
}
