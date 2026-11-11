#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define PLL pair<ll,ll>
#define fi first
#define se second
const ll N=1e5+10;
const ll P=1e9+7;
const ll base1=682739;
const ll base2=748859;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll l,ll r){
	return uniform_int_distribution<ll>(l,r)(rng);
}
struct node{
	ll ls,rs,l,r,sum,lazy;
};
vector<node> tre;
void build(ll l,ll r){
	tre.clear();
	tre.push_back({-1,-1,l,r,0,0});
}
void pushdown(ll u){
	ll mid=(tre[u].l+tre[u].r)/2;
	if(tre[u].ls==-1){
		tre.push_back({-1,-1,tre[u].l,mid,0,0});
		tre[u].ls=tre.size()-1;
	}
	tre[tre[u].ls].sum+=tre[u].lazy*(tre[tre[u].ls].r-tre[tre[u].ls].l+1);
	tre[tre[u].ls].lazy+=tre[u].lazy;
	if(tre[u].rs==-1){
		tre.push_back({-1,-1,mid+1,tre[u].r,0,0});
		tre[u].rs=tre.size()-1;
	}
	tre[tre[u].rs].sum+=tre[u].lazy*(tre[tre[u].rs].r-tre[tre[u].rs].l+1);
	tre[tre[u].rs].lazy+=tre[u].lazy;
	tre[u].lazy=0;
}
void pushup(ll u){
	tre[u].sum=tre[u].lazy*(tre[u].r-tre[u].l+1);
	if(tre[u].ls!=-1){
		tre[u].sum+=tre[tre[u].ls].sum;
	}
	if(tre[u].rs!=-1){
		tre[u].sum+=tre[tre[u].rs].sum;
	}
}
void update(ll l,ll r,ll k,ll u=0){
	if(l<=tre[u].l && tre[u].r<=r){
		tre[u].sum+=(tre[u].r-tre[u].l+1)*k;
		tre[u].lazy+=k;
		return;
	}
	ll mid=(tre[u].l+tre[u].r)/2;
	if(l<=mid){
		if(tre[u].ls==-1){
			tre.push_back({-1,-1,tre[u].l,mid,0,0});
			tre[u].ls=tre.size()-1;
		}
		update(l,r,k,tre[u].ls);
	}
	if(r>mid){
		if(tre[u].rs==-1){
			tre.push_back({-1,-1,mid+1,tre[u].r,0,0});
			tre[u].rs=tre.size()-1;
		}
		update(l,r,k,tre[u].rs);
	}
	pushup(u);
}
ll query(ll l,ll r,ll u=0){
	if(l<=tre[u].l && tre[u].r<=r){
		return tre[u].sum;
	}
	if(r<tre[u].l || l>tre[u].r){
		return 0;
	}
	pushdown(u);
	ll res=0;
	ll mid=(tre[u].l+tre[u].r)/2;
	if(l<=mid){
		res+=query(l,r,tre[u].ls);
	}
	if(r>mid){
		res+=query(l,r,tre[u].rs);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}
/*
100+100+(8+rand)+0=208
terrible
luogu ShootingStar324(748859)
T1 double pointer
T2 floyd
T3 emm
T4 SegmentTree & BalanceTree :)
goodbye
seems a little, awkward(?)
*/