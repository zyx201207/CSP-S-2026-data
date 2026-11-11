#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,q,cnt,len[1010],ans[1010][1010],L[1010][30],R[1010][30],k[510],head[600010],w[600010],s[600010];
struct no{
	int next,pre,z;
}a[2000010];
void add(int x,int y,int z){
	a[++cnt]=(no){head[x],y,z};
	head[x]=cnt;
}
void add1(int x,int y,int z){len[x]++;L[x][len[x]]=y;R[x][len[x]]=z;}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >D;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lax=0,lay=0;
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			if(k[i]==2&&j==2&&x<=1000&&lax<=1000){
				add1(x,lax,lay+y);
				add1(lax,x,lay+y);
			}
			add(x,m+i,y);
			add(m+i,x,y);
			lax=x,lay=y;
		}
			
		
	}
	if(c<=6||c>=11){
		while(q--){
			int l,r;
			cin>>l>>r;
			for(int i=1;i<=n+m;i++)s[i]=1e18;
			s[l]=0;
			D.push({s[l],l});
			while(!D.empty()){
				int x=D.top().first;
				int id=D.top().second;
				D.pop();
				if(s[id]==x){
					for(int i=head[id];i;i=a[i].next){
						int sx=a[i].pre;
						int sy=a[i].z;
						if(sy+x<s[sx]){
							s[sx]=sy+x;
							D.push({s[sx],sx});
						}
					}
				}
			}
			cout<<s[r]+w[l]+w[r]<<"\n";
		}		
	}
	else if(c<=11){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				s[j]=1e18;
				if(j==i)s[j]=0;
				D.push({s[j],j});
			}
			while(!D.empty()){
				int x=D.top().first;
				int id=D.top().second;
				D.pop();
				if(s[id]==x){
					for(int j=1;j<=len[id];j++){
						int sx=L[id][j];
						int sy=R[id][j];
						if(sy+x<s[sx]){
							s[sx]=sy+x;
							D.push({s[sx],sx});
						}
					}
				}
			}
			for(int j=1;j<=m;j++)ans[i][j]=s[j];
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			cout<<ans[l][r]+w[l]+w[r]<<"\n";
		}
	}
}
