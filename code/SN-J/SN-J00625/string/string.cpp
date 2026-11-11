//袁浩文 西安辅轮中学 SN-J00625 
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define elif else if
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define setdigit(x) cout<<fixed<<precision(x)
#define debug(...) fprintf(stderr,##__VA_ARGS__)
using namespace std;
pair<int,char>a[200005];
int n,tot,ans;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char ch;
		cin>>x>>ch;
		if(a[tot].se==ch)a[tot].fi+=x;
		else a[++tot]={x,ch};
	}
//	debug("now tot %lld\n",tot);
	if(tot==1){cout<<0;return;}
	int l=1,r=tot,lcnt=a[l].fi,rcnt=a[r].fi;
	while(l<r){
		if(a[l].se==a[r].se){
			int mi=min(lcnt,rcnt);lcnt-=mi,rcnt-=mi;
			if(lcnt==0)lcnt=a[++l].fi;
			if(rcnt==0)rcnt=a[--r].fi;
		}else{
			int mi=min(lcnt,rcnt);lcnt-=mi,rcnt-=mi,ans+=mi;
			if(lcnt==0)lcnt=a[++l].fi;
			if(rcnt==0)rcnt=a[--r].fi;
		}
	}
	cout<<ans;
}
signed main(){
	string filename="string";
	freopen((filename+".in").c_str(),"r",stdin),freopen((filename+".out").c_str(),"w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Case=1;
//	cin>>Case;
	while(Case--)solve();
}
//9:02
