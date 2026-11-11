#include<iostream>
#include<vector>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,x;
vector<ll> a;
int ans[500006],by[500006];
bool flag=0;
ll fastread(){
	int c=getchar();
	ll ans=0;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())ans=ans*10+(c^48);
	return ans;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=fastread(),m=fastread();
	for(ll i=0;i<n;i++){
		x=fastread();
		by[x]++;
		if(by[x]>1)flag=1;
		a.push_back(x);
	}
	if(m==1){
		for(int i=0;i<m;i++)cout<<"1 ";
	}
	if(flag==0){
		for(int i=n;i>0;i--)cout<<i<<' ';
		return 0;
	}
	for(ll i=1;i<=n;i++){
		vector<ll> b;
		for(ll j=i;j<=n;j++){
			ll er=-1;
			if(by[a[j]]!=0) er=by[a[j]];
			if(er==-1){
				b.push_back(a[j]);
				by[a[j]]=b.size();
			}else{
				for(ll z=n-1;z>=er;z--) b.pop_back();
				b.push_back(a[j]);
				by[a[j]]=b.size();
			}
		}
		for(ll j=0;j<=b.size();j++) ans[b[j]]++;
		for(ll j=0;j<m;j++) by[j]=0;
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
