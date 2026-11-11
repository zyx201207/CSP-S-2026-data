#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll read() {
	ll ret=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n=read(),len=0;
	vector<pair<ll,char>> str(n+1);
	for(int i=1; i<=n; i++) str[i]= {read(),getchar()},len+=str[i].first;
	ll mid=len/2;
	bool isj=len&1;
	vector<pair<ll,char>> now(1);
	ll sum=0;
	for(int i=1; i<=n; i++) {
		ll lst=sum;
		sum+=str[i].first;
		if(mid>lst&&mid<sum) {
			now.push_back({mid-lst,str[i].second});
			now.push_back({sum-mid-isj,str[i].second});
		} else if(mid>=lst&&mid==sum) {
			now.push_back(str[i]);
			str[i+1].first-=isj;
		} else now.push_back(str[i]);
	}
	ll ans=0,l=0,r=now.size()+1,rrst=0,lrst=0;
	while(l<r) {
		if(!lrst) lrst=now[++l].first;
		if(!rrst) rrst=now[--r].first;
		if(l>=r) break;
		ll cur=min(lrst,rrst);
		if(now[l].second!=now[r].second) {
			ans+=cur;
			lrst-=cur;
			rrst-=cur;
		} else {
			lrst-=cur;
			rrst-=cur;
		}
	}
	cout<<ans;
	return 0;
}