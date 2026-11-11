#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,lpos,rpos,Llen,Rlen;
ll a[N],L[N],R[N];
ll tot,Ln,Rn,ans;
char c[N],Lc[N],Rc[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],tot+=a[i];
    ll lim=tot/2,now=0;
    for(int i=1;i<=n;i++){
		L[++Llen]=min(a[i],lim-now);
		Lc[Llen]=c[i];
		now+=min(a[i],lim-now);
		if(now==lim)break;
	}
	now=0;
	for(int i=n;i;i--){
		R[++Rlen]=min(a[i],lim-now);
		Rc[Rlen]=c[i];
		now+=min(a[i],lim-now);
		if(now==lim)break;
	}
	lpos=1,Ln=L[lpos];
	while(lpos<Llen&&rpos<Rlen){
		if(Ln<Rn){
			lpos++;
			if(Rc[rpos]!=Lc[lpos])ans+=min(L[lpos],Rn-Ln);
			Ln+=L[lpos];
		}
		else{
			rpos++;
			if(Lc[lpos]!=Rc[rpos])ans+=min(R[rpos],Ln-Rn);
			Rn+=R[rpos];
		}
	}
	while(lpos<Llen){
		lpos++;
		if(Rc[rpos]!=Lc[lpos])ans+=L[lpos];
	}
	while(rpos<Rlen){
		rpos++;
		if(Lc[lpos]!=Rc[rpos])ans+=R[rpos];
	}
	cout<<ans<<'\n';
    return 0;
}