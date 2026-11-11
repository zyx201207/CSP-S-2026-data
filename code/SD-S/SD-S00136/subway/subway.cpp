#include<bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
const int maxn=500+50,maxm=5e5+50,maxx=0x3f3f3f3f3f3f3f3f;
int w[maxn],k[maxn],q[maxn];
int a[maxm],t[maxm];
int o[maxm];

int geta(int x,int y){ return a[q[max(x-1,0ll)]+y]; }
int gett(int x,int y){ return t[q[max(x-1,0ll)]+y]; }
int geto(int x,int y){ return o[q[max(x-1,0ll)]+y]; }
void seta(int x,int y,int v){ a[q[max(x-1,0ll)]+y]=v; }
void sett(int x,int y,int v){ t[q[max(x-1,0ll)]+y]=v; }
void seto(int x,int y,int v){ o[q[max(x-1,0ll)]+y]=v; }

vector<pair<int,int> > vec[maxm];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		q[i]=q[i-1]+k[i];
		for (int j=1;j<=k[i];j++){
			int l1,l2;
			cin>>l1>>l2;
			seta(i,j,l1);sett(i,j,l2);
			vec[l1].push_back({i,j});
		}
	}
	while (p--){
		for (int i=1;i<=maxm;i++) o[i]=maxx;
		int ans=maxx;
		int x,y;
		cin>>x>>y;
		stack<pair<pair<int,bool>,int>> st;
		st.push({{0,x},0});
		while (!st.empty()){
			auto s=st.top();
			st.pop();
			if (s.s>ans) continue;
			for (int i=1;i<=k[s.f.f];i++) if (geta(s.f.f,i)==y) ans=min(ans,s.s+gett(s.f.f,i)+w[y]);
			if (s.f.f==0){
				for (int l=0;l<vec[x].size();l++) {
					int i=vec[x][l].f,j=vec[x][l].s;
					
					st.push({{i,j},w[i]+gett(i,j)});
					seto(i,j,w[i]+gett(i,j));
				}
			}
			else{
				int i=s.f.f;
				for (int j=1;j<=k[i];j++){
//					if (geto(i,j)) continue;
//					seto(i,j);
					
					for (int _=0;_<vec[geta(i,j)].size();_++) {
						int k=vec[geta(i,j)][_].f,l=vec[geta(i,j)][_].s;
						if (k==i&&l==j||k==i) continue;
						if (s.s+gett(i,j)+gett(k,l)>geto(k,l)) continue;
						
						st.push({{k,l},s.s+gett(i,j)+gett(k,l)});
						
						seto(k,l,s.s+gett(i,j)+gett(k,l));
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

//Oct31==Dec25?


