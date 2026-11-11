#include<bits/stdc++.h>
using namespace std;
const int N =200010;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b,l=0,maxn=0;
    int a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		b=(a[i]&a[j]);
	}
	maxn=max(maxn,b);
	}
	cout<<maxn;
	return 0;
}
