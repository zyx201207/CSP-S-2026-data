#include<bits/stdc++.h>
using namespace std;
#define C ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
ll a[200005];
int main(){
	C
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	ll maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	cout<<maxx;
	return 0;
}
