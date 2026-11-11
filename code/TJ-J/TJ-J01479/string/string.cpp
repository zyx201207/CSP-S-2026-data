#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node{
	ll u,v;
};ll ans=0;
node a[200015];
ll num[200015];
int main(){//1145141919810
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll cur=0;
	ll rpos=0;
	for(ll i=1;i<=n;i++){
		ll t;char x;
		cin>>t>>x;
		num[i]=(int)x;
		a[i].u=cur+1;
		a[i].v=a[i].u+t-1;
		cur+=t;
		rpos+=t;
	}
	ll l=1,r=n;
	ll lpos=1;
	while(l<r){
		
		if(num[l]!=num[r]){
			//cout<<a[l].v-lpos+1<<' '<<rpos-a[r].u+1<<'/';
			if(a[l].v-lpos+1 <= rpos-a[r].u+1){
				ans+=a[l].v-lpos+1;
			}else ans+=rpos-a[r].u+1;
		}
		if(a[l].v-lpos+1 < rpos-a[r].u+1 ){
			rpos-=(a[l].v-lpos) +1;
			lpos=a[l].v+1;
			l++;
		}else if(a[l].v-lpos+1 > rpos-a[r].u+1 ){
			lpos+=(rpos-a[r].u) +1;
			rpos=a[r].u-1;
			r--;
		}else if(a[l].v-lpos+1 == rpos-a[r].u+1){
			
			rpos-=(a[l].v-lpos) +1;
			lpos+=(rpos-a[r].u) +1;
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
