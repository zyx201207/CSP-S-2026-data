#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+5;
ll n,cnt=0,ans,previx[N],suffix[N];
struct node{
	char c;
	ll x;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a[i].x>>a[i].c;
		cnt+=a[i].x;
	}
	ll temp=0; 
	node pre;
	bool flag=false; 
	for(ll i=1;i<=n;++i){
		temp+=a[i].x;
		if(temp==cnt/2){
			if(cnt%2!=0){
				--a[i+1].x;
			}
			break;
		}
		else if(temp>cnt/2){
			if(flag)swap(pre,a[i]);
			else{
				++n;
				pre.c=a[i].c,pre.x=a[i].x-temp+cnt/2,swap(pre,a[i]);
				pre.x=temp-cnt/2;
				if(cnt%2!=0)--pre.x;
			}
			flag=true;
		}
	}
	for(ll i=1;i<=n;++i){
		previx[i]=previx[i-1]+a[i].x;
	}
	for(ll i=n;i>=1;--i){
		suffix[i]=suffix[i+1]+a[i].x;
	}
	ll cnt1=0,cnt2=0,c=0;
	for(ll i=1,j=n;i<j;){
			if(previx[i]<suffix[j]){
				cnt1+=a[i].x;
				cnt2+=a[i].x;
				
				if(a[i].c!=a[j].c){
					ans+=previx[i]-c;
				}
				c=previx[i];
				++i;
			}
			else if(previx[i]>suffix[j]){
				
				if(a[i].c!=a[j].c){
					ans+=suffix[j]-c;
				}
				c=suffix[j];
				--j;
			}
			else{
				if(a[i].c!=a[j].c){
					ans+=min(previx[i]-c,suffix[j]-c);
				}
				c=previx[i];
				++i;
				--j;
			}
	}
	cout<<ans;
	return 0;
}

