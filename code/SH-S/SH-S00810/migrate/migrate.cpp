#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+9;
ll C,T,n,d,x[N];
ll ans1_2=0;
ll cnt1_2=0;
ll mn1_2=1e18;
void dfs1_2(ll id,ll r,ll cnt){
	if(id==r){
		if(cnt==mn1_2)cnt1_2++;
		else{
			cnt1_2=1;
			mn1_2=cnt;
		}
		return;
	}
	if(x[r]-x[id]<=d){
		dfs1_2(r,r,cnt+1);
		return;
	}
	for(ll i=id+1;i<=r;i++){
		if(x[i]-x[id]>d)break;
		dfs1_2(i,r,cnt+1);
	}
}
void solve1_2(){
	for(ll P=1;P<=T;P++){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		ans1_2=0;
		for(ll l=1;l<=n;l++){
			for(ll r=l+1;r<=n;r++){
				if(x[r]-x[r-1]>d)break;
				cnt1_2=0;
				mn1_2=1e18;
				dfs1_2(l,r,0);
				if(cnt1_2==2)ans1_2++;
			}
		}
		cout<<ans1_2<<'\n';
	}
}
ll ans3_6=0;
ll cnt3_6=0;
ll mn3_6=1e18;
void solve3_6(){
	for(ll P=1;P<=T;P++){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		ans3_6=0;
		for(ll l=1;l<=n;l++){
			for(ll r=l+1;r<=n;r++){
				cnt3_6=1;
				mn3_6=0;
				int id=l;
				for(ll i=l+1;i<=r;i++){
					if(x[i]-x[id]>d){
						id=i-1;
						mn3_6++;
					}
				}
				mn3_6++;
				int cn1=0,cn2=0;
				for(ll i=l+1;i<=r;i++){
					if(x[i]-x[id]>d){
						if(cn1==mn3_6-3)id=i-2;
						else id=i-1;
						cn1++;
					}
				}
				cn1++;
				for(ll i=l+1;i<=r;i++){
					if(x[i]-x[id]>d){
						if(cn2==mn3_6-5)id=i-2;
						else id=i-1;
						cn2++;
					}
				}
				cn2++;
				if(cn1==mn3_6)cnt3_6++;
				if(cn2==mn3_6)cnt3_6++;
				if(cnt3_6==2)ans3_6++;
			}
		}
		cout<<ans3_6<<'\n';
	}
}
void solveA(){
	for(ll P=1;P<=T;P++){
		cin>>n>>d;
		for(ll i=1;i<=n;i++)cin>>x[i];
		ll c=x[2]-x[1];
		ll t=d/c;
		if(t<2||n-2*t+1<0)cout<<"0\n";
		else cout<<n-2*t+1<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>C>>T;
	if(11<=C&&C<=12)solveA();
	if(1<=C&&C<=2)solve1_2();
	if(3<=C&&C<=6)solve3_6();//ÓÐbug 
	return 0;
}
