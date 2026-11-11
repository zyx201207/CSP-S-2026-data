#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll a;
	char c;
}a[200010];
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].a>>a[i].c;
	ll l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c) ans+=min(a[l].a,a[r].a);
		if(a[l].a>a[r].a){
			a[l].a-=a[r].a;
			r--;
		}else if(a[l].a==a[r].a){
			l++;
			r--;
		}else{
			a[r].a-=a[l].a;
			l++;
		}
	}
	cout<<ans;
	return 0; 
}
//rp++!
//有一点难度的黄题 
