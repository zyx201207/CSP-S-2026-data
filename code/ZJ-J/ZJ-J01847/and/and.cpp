#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
long long ans,a[N];
void mm(long long x,int k,int s){
	if(s>m){
		ans=max(ans,x);
		return;
	}
	if(k>n) return;
	mm(x,k+1,s);
	mm(x&a[k],k+1,s+1);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		mm(a[i],i,1);
	}
	cout<<ans;
	return 0;
}

