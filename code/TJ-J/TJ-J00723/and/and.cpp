#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long maxn=a[1];
	for(long long i=2;i<=m;i++){
		maxn=maxn&a[i];
	}
	cout<<maxn;
	return 0;
}
