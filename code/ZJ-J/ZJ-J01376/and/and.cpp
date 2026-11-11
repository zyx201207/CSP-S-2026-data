#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=0;
int a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,a[i]&a[j]); 
		}
	}
	cout<<maxn;
	return 0;
}