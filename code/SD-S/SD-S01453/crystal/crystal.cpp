#include<bits/stdc++.h>
using namespace std;
#define C ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
ll a[500005];
int v[1000005];
int main(){
	C
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	int maxx=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
		maxx=max(maxx,v[a[i]]);
	}
	if(m==0){
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	int y=abs(abs(a[n])-abs(a[n-1]));
	int sum=1;
	for(int i=n-1;i>=1;i--){
		if(m-y*(n-i)>=0){
			m-=y*(n-i);
			sum++;
		}
	}
	maxx=max(maxx,sum);
	cout<<maxx;
	return 0;
}
