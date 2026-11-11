#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
ll t[200005];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		t[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	if(t[a[1]]>1){
		cout << a[t[a[1]]+1];
	}
}