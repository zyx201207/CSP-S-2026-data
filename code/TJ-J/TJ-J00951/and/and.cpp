#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	else if(m=n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn= maxn & a[i];
		}
	}
	else if(m=2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;i++){
				maxn=max(maxn,a[i] & a[j]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
