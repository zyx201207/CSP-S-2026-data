#include<bits/stdc++.h>

using namespace std;

#define int long long

#define rp(i,j,k) for(int i=(j);i<=(k);i++)
#define pr(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
void gmin(int &x,int y){x=min(x,y);}
void gmax(int &x,int y){x=max(x,y);}

namespace SOLVE{
	
const int N=2e5+5;
int n,a[N],L,s,ans;
char c[N];
vector<pii>vL,vR;

void solve(){
	cin>>n;
	L=ans=0;
	rp(i,1,n)
		cin>>a[i]>>c[i],L+=a[i];
	s=0;
	rp(i,1,n){	
		vL.eb(min(L/2-s,a[i]),c[i]-'a');
		s+=min(L/2-s,a[i]);
		if(s>=L/2)break;
	}
	s=0;
	pr(i,n,1){
		vR.eb(min(L/2-s,a[i]),c[i]-'a');
		s+=min(L/2-s,a[i]);
		if(s>=L/2)break;
	}
	int i=0,j=0;
	while(i<(int)vL.size()&&j<(int)vR.size()){
		if(vL[i].fi<vR[j].fi){
			if(vL[i].se!=vR[j].se)ans+=vL[i].fi;
			vR[j].fi-=vL[i].fi;i++;
		}else if(vL[i].fi>vR[j].fi){
			if(vL[i].se!=vR[j].se)ans+=vR[j].fi;
			vL[i].fi-=vR[j].fi;j++;
		}else{
			if(vL[i].se!=vR[j].se)ans+=vL[i].fi;
			i++;j++;
		}
	}
	cout<<ans<<"\n";
	return;
}

}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;//cin>>_;
	while(_--)SOLVE::solve();
	return 0;
}
