#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n,a[N],pre[N],ans;
char c[N];
ll fd(ll p){return lower_bound(pre+1,pre+1+n,p)-pre;}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
	}
	ll l,r;
	if(pre[n]&1){
		l=pre[n]/2;
		r=pre[n]/2+2;
	}else{
		l=pre[n]/2;
		r=pre[n]/2+1;
	}
	while(l>=1&&r<=pre[n]){
		ll fl=fd(l),fr=fd(r);
		ll lenl=l-pre[fl-1],lenr=pre[fr]-r+1;
		if(lenl<lenr){
			l-=lenl;
			r+=lenl;
			if(c[fl]!=c[fr])ans+=lenl;
		}else{
			l-=lenr;
			r+=lenr;
			if(c[fl]!=c[fr])ans+=lenr;
		}
	}
	cout<<ans;
	return 0;
}