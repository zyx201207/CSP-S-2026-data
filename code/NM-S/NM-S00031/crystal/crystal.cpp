#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a1[592778],b1[592778];
struct node{
	ll num,mem;
	bool if_all;
}a[592778];
bool cpt(node x,node y){
	if(x.num==y.num) return x.mem<y.mem;
	return x.num<y.num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a1[i];
	}
	sort(a1+1,a1+n+1);
	ll count=1;
	a[1].mem=a1[1];
	a[1].num=1;
	for(int i=2;i<=n;i++){
		if(a1[i]!=a[count].mem){
			count++;
			a[count].if_all=0;
			a[count].mem=a1[i];
			a[count].num++;
			continue;
		}
		a[count].if_all=0;
		a[count].num++;
	}
	sort(a+1,a+1+count,cpt);
	for(int i=count;i>=1;i--){
		ll delta=0x7fff;
		ll record=0,l=count-1;
		ll val;
		while(l>0){
			if(a[l].if_all=1){
				l--;
				continue;
			}
			val=abs(a[count].mem-a[l].mem);
			if(delta>=val){
				delta=val;
				record=l;
			}
			l--; 
		}	
		ll total=abs((a[record].num)*delta);
		if(m>total){
			m-=total;
			ans+=total;
			a[record].if_all=1;
			continue;
		}
		else{
			ans+=m;
			break;
		}
	}
	cout<<ans;
}
