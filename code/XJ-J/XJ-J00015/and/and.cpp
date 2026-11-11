#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n,m,maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	maxn=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxn=max(a[i]&a[j],maxn);
			}
		}
	}
	while(m--){
		for(int i=1;i<=n;i++){
			maxn=max(a[i]&a[i+1],maxn);
		}
		m--;
	}
	cout<<maxn;
	return 0;
} 
