//liushaoang SN-J00738 FuLun
#include<bits/stdc++.h>
#define st string
#define ll long long
using namespace std;
ll a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll q=a[1];
	ll e=a[2];
	cout<<(q&e);
	return 0;
}
 
