#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,m,now,last,next;
ll a[202000],d[202000];
char c[202000];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
	return 0;
}
