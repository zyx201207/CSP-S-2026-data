#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node{
	ll cnt;
	char c;
};
Node a[200010];
ll n;
ll mcnt;
ll ans;
string s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		mcnt+=a[i].cnt;
	}
	ll l=1,r=n,ls=a[1].cnt,rs=a[n].cnt;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(ls<rs){
				l++;
				ls=a[l].cnt;
				rs=a[r].cnt-a[l-1].cnt;
			}else if(ls>rs){
				r--;
				rs=a[r].cnt;
				ls=a[l].cnt-a[r+1].cnt;
			}else{
				l++;
				r--;
				ls=a[l].cnt;
				rs=a[r].cnt;
			}
		}else{
			ans+=min(ls,rs);
			if(ls<rs){
				l++;
				ls=a[l].cnt;
				rs=a[r].cnt-a[l-1].cnt;
			}else if(ls>rs){
				r--;
				rs=a[r].cnt;
				ls=a[l].cnt-a[r+1].cnt;
			}else{
				l++;
				r--;
				ls=a[l].cnt;
				rs=a[r].cnt;
			}
		}
	}
	cout<<ans;
	return 0;
}