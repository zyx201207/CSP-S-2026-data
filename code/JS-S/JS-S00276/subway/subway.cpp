//WOW! A DETECT-LIKE PROBLEM!
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define ins insert
#define int long long
#define pii pair<long long,long long>
#define endl "\n"
int n,m,c,d,q,gate[500012],k,floyd[512][512],num,ans;
vector<pii> accum[500012];
int in(){
	int flag=1,ans=0;
	char c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ans=(ans*10ll)+(c-'0');
		c=getchar();
	}
	return ans*flag;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //ios::sync_with_stdio(0);cin.tie(0);
    //cin>>c;cin>>n>>m>>d>>q;
    c=in();n=in();m=in();d=in();q=in();
    memset(floyd,0x3f,sizeof(floyd));
    rep(i,1,m){
		gate[i]=in();
	}
    rep(i,1,n){
		floyd[i][i]=0;
		pii p;p.first=i;
		k=in();
		rep(j,1,k){
			num=in();p.second=in();
			accum[num].pb(p);
		}
	}
	rep(i,1,m){
		pii l,r;int ls=accum[i].size();
		rep(x,0,ls-1)rep(y,x+1,ls-1){
			l=accum[i][x];r=accum[i][y];
			floyd[l.first][r.first]=min(floyd[l.first][r.first],l.second+r.second);
			floyd[r.first][l.first]=min(floyd[r.first][l.first],l.second+r.second);
		}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
	/*rep(i,1,n){
		rep(j,1,n)cout<<floyd[i][j]<<" ";
		cout<<endl;
	}*/
	rep(i,1,q){
		int l,r;ans=0x3f3f3f3f3f3f3f3f;
		l=in();r=in();
		int ls=accum[l].size(),rs=accum[r].size();
		rep(x,0,ls-1)rep(y,0,rs-1){
			int lp=accum[l][x].first,rp=accum[r][y].first;
			//cout<<lp<<" "<<rp<<endl;
			ans=min(ans,floyd[lp][rp]+gate[l]+gate[r]+accum[l][x].second+accum[r][y].second);
		}
		cout<<ans<<endl;
	}
}
//diff -Z -B --suppress-common-lines
//This is CSP-S. Be serious!
