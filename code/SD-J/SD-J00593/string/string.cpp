#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pii pair<int,int>
#define vec vector
#define pic pair<int,char> 
using namespace std;
int n;
ll L=0;
vec<pair<int,char>>od;
vec<pic>vl;
vec<pic>vr;
void solve(){
	cin >> n;
	od.resize(n);
	for(int i=1;i<=n;i++){
		int m;char c;
		cin >> m >> c;
		od[i-1]=make_pair(m,c);
		L+=m;
	}
	ll mid=L+1>>1;
	{
	ll pre=0;
	int i;
	pic lb,rb;
	for(i=0;i<n;i++){
		pre+=od[i].fi;
		if(pre>=mid){
		pre-=od[i].fi;break;
		}
	}lb.se=rb.se=od[i].se;
	if(L&1){
		lb.fi=mid-1-pre;
		rb.fi=pre+od[i].fi-mid;
	}else{
		lb.fi=mid-pre;
		rb.fi=pre+od[i].fi-mid;
	}
	
	int le=0,re=0;
	if(lb.fi){
		vl.resize(i+1);
		vl[le++]=lb;
	}else vl.resize(i);
	if(rb.fi){
		vr.resize(n-i);
		vr[re++]=rb;
	}else vr.resize(n-1-i);
	for(int j=i-1;j>=0;j--){
		vl[le++]=od[j];
	}for(int j=i+1;j<n;j++){
		vr[re++]=od[j];
	}
	}
	ll ans=0;
	int l=0,r=0;
	while(l<vl.size()&&r<vr.size()){
		ll res=min(vl[l].fi,vr[r].fi);
		vl[l].fi-=res;
		vr[r].fi-=res;
		if(vl[l].se!=vr[r].se)ans+=res;
		if(!vl[l].fi)l++;
		if(!vr[r].fi)r++;
	}cout<<ans;
	
}
signed main(){
	IOS;
	freopen("string.in", "r",stdin);
	freopen("string.out","w",stdout);
    //int t;cin >> t;while(t--)
    solve();
    return 0;
}
