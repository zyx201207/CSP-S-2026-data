#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
pair<ll, char>p[200005], fp[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(ll i=1; i<=n; i++){
		cin >> p[i].first >> p[i].second;
		fp[i]=p[i];
	}
	reverse(fp+1, fp+1+n);ll sum=0;
	for(ll i=1, j=1; i<=n; i++){
		ll sz1=p[i].first, sz2=fp[j].first;
		char c1=p[i].second, c2=fp[j].second;
		if(sz1>=sz2)j++, p[i].first-=sz2, i-=(sz1>sz2);
		else fp[j].first-=sz1;
		ll minn=min(sz1, sz2);
		if(c1!=c2)sum+=minn;
	}
	cout<<sum/2;
	return 0;
}

