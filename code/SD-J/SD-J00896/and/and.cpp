#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	int maxx=-54378;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxx){
				maxx=max(a[i]&a[j],maxx);
			}
		}
	}
	cout<<maxx;
	return 0;
}

