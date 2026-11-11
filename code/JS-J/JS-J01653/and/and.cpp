#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void s(int i,long long v,int w){
	if(ans>=v)return;
	if(m==w){
		ans=max(ans,v);
		return;
	}
	if(i>n)return;
	for(;i<=n;i++){
		s(i+1,v&a[i],w+1);
	}
}
int main(){
	scanf("%lld%lld",&n,&m);
	freopen("w","and.in",stdin);
	freopen("r","and.out",stdout);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	s(1,LONG_LONG_MAX,0);
	cout<<ans;
}
