#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=2e5+50;

ll n,m;
ll a[maxn];

int cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1,cmp);
	
	ll sum=a[1];
	for(int i=1;i<=m;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}
