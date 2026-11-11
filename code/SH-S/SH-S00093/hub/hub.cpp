
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define PII pair<int,int>
long long c,n,m,d,qe,y,T;
int dist[1000005],vis[1000005],l,r;
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector <int> v[1000005];
set <int> p;
void mem(){
	memset(dist,0x3f,sizeof(dist));
} 
void dfs(int u,int fa){
	for(auto c:v[u]){
		if(c==fa) continue;
		dist[c]=min(dist[c],dist[u]+1);
		dfs(c,u);
	}
}
void dfs2(int u,int fa){
	if(!p.count(u)) return;
	vis[u]=1;
	for(auto c:v[u]){
		if(c==fa) continue;
		dfs2(c,u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//int n,m;
	cin>>c>>T;
	while(T--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin>>l>>r;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		int maxx=100000000000;
		if(d==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mem();
					dist[i]=0;
					dfs(i,0);
					dist[j]=0;
					dfs(j,0);
					int mmm=-10000;
					for(int i=1;i<=n;i++){
						mmm=max(mmm,dist[i]);
					}
					maxx=min(maxx,mmm);
				}
			}
			cout<<maxx;
		}else if(d==1){
			for(int i=1;i<=n;i++){
				mem();
				dist[i]=0;
				dfs(i,0);
				int mmm=-10000;
				for(int i=1;i<=n;i++){
					mmm=max(mmm,dist[i]);
				}
				maxx=min(maxx,mmm);
			}
			cout<<maxx;
		}else{
			for(int i=(2<<d)-1;i<=(2<<n)-1;i++){
				p.clear();
				if(__builtin_popcount(i)!=d){
					continue;
				}
				string s=" ";
				int rrr=i;
				while(rrr){
					s=s+(char)(rrr%2+'0');
					rrr/=2;
				}
				reverse(s.begin(),s.end());
				mem();
				for(int j=1;j<s.size();j++){
					if(s[j]=='0') continue;
					p.insert(j);
				}
				memset(vis,0,sizeof(vis));
				int sum=0;
				for(auto ll:p){
					if(!vis[ll]){
						sum++;
						dfs2(ll,0);
					}
				}
				if(sum>2) continue;
				for(int j=1;j<s.size();j++){
					if(s[j]=='0') continue;
					dist[j]=0;
					dfs(j,0);
				}
				int mmm=-10000;
				for(int i=1;i<=n;i+=1){
					mmm=max(mmm,dist[i]);
				}
				if(mmm<maxx){
					maxx=mmm; 
				//	if(mmm==1) for(auto c:p) cout<<c<<" ";
				//	cout<<"\n";
				}
			//	cout<<"\n";
			}
			cout<<maxx;
		}
		cout<<"\n";
	}
	
} 
/* 继续写游记：
90+ 84~100 +0~10+30~45
204~245？？？
我重生了，重生在csp-s的考场，这一次，我一定要上迷惑大赏！
florrlv102 
*/ 

