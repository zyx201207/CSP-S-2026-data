#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
struct node{
	ll d;
	char c;
}a[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int idx=0;
	for(int i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		if(idx==0){
			idx++;
			a[idx].c=y;
			a[idx].d=x;
			continue;
		}
		if(y==a[idx].c){
			a[idx].d+=x;
		}else{
			idx++;
			a[idx].c=y;
			a[idx].d=x;
		}
	}
	int p=1,q=idx;
	ll ans=0;
	while(true){
		if(p>=q) break;
		if(a[p].d<=a[q].d){
			a[q].d-=a[p].d;
			if(a[p].c!=a[q].c) ans+=a[p].d;
			p++;
			if(a[q].d==0) q--;
		}else{
			a[p].d-=a[q].d;
			if(a[p].c!=a[q].c) ans+=a[q].d;
			q--;
		}
	}
	cout<<ans;
	return 0;
}
