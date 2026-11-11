//今天是万圣节吗？ 
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int c,n,m,dd,q;
int qwq[510];
vector<pii>ohno[510];
int head[1010],nt[1010],to[1010],w[1010];
int E;
struct node{
	int ft,sd,road;
};
void add(int a,int b,int c){
	w[E]=c;
	to[E]=b;
	nt[E]=head[a];
	head[a]=E;
	E++;
}
vector<node> vt[510]; 
int mp[510][510];
int d[510][510];
int st,ed;
queue<int>qqq[510];
int zzz=0;
void bfs(int st){
	queue<int>qq[510];
	memset(d[st],0x3f,sizeof d[st]);
	queue<int>q;
	q.push(st);
	d[st][st]=0;
	int rd=0;
	bool flag=0;
	int last=st;
	int cnt=0;
	qq[cnt].push(st);
	while(q.size()){
		int op=q.front();
		q.pop();
		if(op==ed){
			//cout<<cnt<<"\n";
			zzz=qq[cnt-2].front();
			return;
		}
		for(auto i:vt[op]){
			int x=i.ft,y=i.sd,z=i.road;
			if(rd==0){
				rd=z;
			}else{
				if(rd!=z){
					flag=1;
				}else{
					flag=0;
				}
			}
			last=qq[cnt-1].front();
			int awa=0;
			for(auto j:vt[op]){
				if(j.ft==last){
					awa=j.sd;
				}
			}
			if(d[st][x]>d[st][op]+y+awa){
				d[st][x]=d[st][op]+y;
				if(flag){
					d[st][x]+=awa;
				}
				q.push(x);
				if(x==ed){
					zzz=qq[cnt-1].front();
					return;
				}
				qq[cnt+1].push(x);
			}
		}
		//cout<<op<<' '<<cnt<<"\n";
		cnt++;
	}
}//空悲切 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	memset(head,-1,sizeof head);
	for(int i=1;i<=m;i++){
		cin>>qwq[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ohno[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<ohno[i].size()-1;j++){
			auto fst=ohno[i][j],snd=ohno[i][j+1];
			int fa=fst.first,ft=fst.second;
			int sa=snd.first,st=snd.second;
			vt[fa].push_back({sa,ft,i});
			vt[sa].push_back({fa,st,i});
			add(fa,sa,ft);
			add(sa,fa,st);
			mp[fa][sa]=ft;
			mp[sa][fa]=st;
		}
	}
	while(q--){
		cin>>st>>ed;
		bfs(st);
		int ans=d[st][ed]+qwq[st]+qwq[ed];
		//cout<<zzz<<"\n";
		for(auto i:vt[ed]){
			int x=i.ft,y=i.sd;
			if(x==zzz){
				ans+=y;
				//cout<<"y:"<<y<<"\n";
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

