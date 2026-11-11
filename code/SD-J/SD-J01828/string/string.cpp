#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
ll ans=0;
struct node{
	ll l,r,x;
	char s;
}a[200010];
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		char ab;
		ll ba;
		cin>>ba>>ab;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+ba-1;
		a[i].s=ab;
		a[i].x=a[i].r-a[i].l+1;
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l].x==a[r].x){
			if(a[l].s==a[r].s){
				l++,r--;
				continue;
			}else{
				ans+=a[l].x;
				l++,r--;
				continue;
			}
		}else if(a[l].x>a[r].x){
			a[l].x-=a[r].x;
			if(a[l].s==a[r].s){
				r--;
				continue;
			}else{
				ans+=a[r].x;
				r--;
				continue;
			}
		}else{
			a[r].x-=a[l].x;
			if(a[l].s==a[r].s){
				l++;
				continue;
			}else{
				ans+=a[l].x;
				l++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
