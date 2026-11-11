#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct q{
	ll b;
	char c;
}a[200005];
ll n,r,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	r=n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
	}
	for(ll i=1;i<r;i++){
		if(a[i].c!=a[r].c){
			cnt+=min(a[i].b,a[r].b);
			if(a[i].b<a[r].b){
				a[r].b-=a[i].b;
				a[i].b=0;
			}else if(a[i].b==a[r].b){
				a[r].b=0;
				a[i].b=0;
				r--;
			}else{
				a[i].b-=a[r].b;
				i--;
				a[r].b=0;
				r--;
			}
		}else{
			if(a[i].b<a[r].b){
				a[r].b-=a[i].b;
				a[i].b=0;
			}else if(a[i].b==a[r].b){
				a[r].b=0;
				a[i].b=0;
				r--;
			}else{
				a[i].b-=a[r].b;
				i--;
				a[r].b=0;
				r--;
			}
		}
		
	}
	cout<<cnt;
	return 0;
}

