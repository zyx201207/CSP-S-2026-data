#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
struct node{
	ll a;
	char c;
}p[N];
int n,l,r;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> p[i].a >> p[i].c;
	}
	l=1,r=n;
	while(l<=r){
		if(p[l].c!=p[r].c) ans++;
		p[l].a--;
		p[r].a--;
		if(p[l].a<=0) l++;
		if(p[r].a<=0) r--;
	}
	cout << ans;
	return 0;
}