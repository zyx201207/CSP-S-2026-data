#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,t;
struct no{
	int a,b;
};
bool cmp(no a,no b){
	return a.b<b.b;
}
no e[10000009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cout<<e[1].a;
	for(ll i=2;i<=n;i++){
		cout<<e[i].a;
		e[i].b=e[i].a-e[i-1].a;
	}
	sort(e+1,e+1+n,cmp);
	for(ll i=2;i<=n;i++){
		t+=t+e[i].b;
	}
	cout<<t;
	return 0;
}
