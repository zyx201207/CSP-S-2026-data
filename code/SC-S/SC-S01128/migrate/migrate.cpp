#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef long long ll;

const int N=2e6+5,inf2=1e9;
const ll inf=1e18+2;
int c,t;
int n;
ll d,a[N];
int ne[N];
bool vis[N];
struct node{
	int l,r;
};
int bp[N];

bool cmp(node a,node b){
	return (a.r==b.r)?a.l>b.l:a.r<b.r;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		int ml=0;
		int cnt=0;
		vector<node> seg,ss,wx;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[n+1]=inf;
		for(int i=1;i<=n;i++){
			int pos=upper_bound(a+i,a+1+n,a[i]+d)-a-1;
			ne[i]=pos;
		}
		for(int i=1;i<=n;i++){
			if(ne[i]==i){
				bp[++cnt]=i;
				continue;
			}
			if(ne[ne[i]]!=ne[i]&&ne[ne[i]]==ne[ne[i]-1]&&ne[ne[i]]!=ne[ne[i]-2]){
				seg.push_back({i,ne[ne[i]-2]+1});
			}
		}
		sort(seg.begin(),seg.end(),cmp);
		memset(vis,0,sizeof vis);
		for(int i=1;i<seg.size();i++){
			if(seg[i].l==seg[i-1].l&&seg[i].r==seg[i-1].r) vis[i-1]=vis[i]=1;
		}
		for(int i=0;i<seg.size();i++){
			if(!vis[i]) ss.push_back({seg[i].l,seg[i].r});
		}
		memset(vis,0,sizeof vis);
		for(int i=0;i<ss.size();i++){
			if(ss[i].l<=ml) vis[i]=1;
			ml=max(ml,ss[i].l);
		}
		wx.push_back({0,0});
		for(int i=0;i<ss.size();i++){
			if(!vis[i]){
				wx.push_back({ss[i].l,ss[i].r});
			}
		}
		bp[++cnt]=n+1;
		wx.push_back({n+1,n+1});
		for(int i=1;i<wx.size()-1;i++){
			int num1=bp[lower_bound(bp+1,bp+1+cnt,wx[i].l)-bp-1]+1;
			int num2=bp[lower_bound(bp+1,bp+1+cnt,wx[i].r)-bp];
			if(num2<wx[i].r) num2=inf2;
			ll pl=max(wx[i-1].l+1,num1);
			ll pr=min(wx[i+1].r-1,num2);
			ans+=(ll)(wx[i].l-pl+1)*(ll)(pr-wx[i].r+1);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}