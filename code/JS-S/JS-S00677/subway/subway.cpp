#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
vector<pair<int,int>>to[maxn];
map<pair<int,int>,long long>trans;
vector<int>lines[505],k(505);
int penalty[maxn];
set<int>connections[maxn];
int n,m,q;
bool vis[maxn];
//DO NOT TOUCH F11
//THIS IS TO THE HOST
struct dfs{
	int cur;
	int last;
	int lastline;
	long long used;
};
long long ans(int s,int t){
	memset(vis,0,sizeof vis);
	long long ans=0x3f3f3f3f3f3f3f3f;
	queue<dfs>q;
	q.push({s,s,0,0});
	while(!q.empty()){
		dfs top=q.front();
		q.pop();
		if(top.cur==t){
			ans=min(ans,top.used);
		}
		if(vis[top.cur])continue;
		vis[top.cur]=1;
		for(int i=0;i<to[top.cur].size();i++){
			if(to[top.cur][i].second!=top.lastline){
				q.push({to[top.cur][i].first,top.cur,to[top.cur][i].second,top.used+trans[{top.cur,top.lastline}]+trans[{top.cur,to[top.cur][i].second}]});
			}
			else{
				q.push({to[top.cur][i].first,top.cur,to[top.cur][i].second,top.used});
			}
		}
	}
	ans+=penalty[s]+penalty[t];
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1,c,d;i<=1;i++)
		cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",penalty+i);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1,a,t;j<=k[i];j++){
			scanf("%d%d",&a,&t);
			lines[i].push_back(a);
			trans[{a,i}]=t;
			connections[a].insert(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			to[j-1].push_back({j,i});
			to[j].push_back({j-1,i});
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%lld\n",ans(x,y));
	}
	return 0;
}
//AFOed, HC Zhu, Oct 31, 17:22:16
//failure.cpp
/*
#include<bits/stdc++.h>
using namespace std;
int maxn=5e5+6;
int n,m,q;
map<pair<int,int>,long long>trans;
vector<int>line[505];
int k[505];
int penalty[maxn];
set<int>stat[maxn];
struct dfsNode{
        int station;
        int curLine;
        int curTime;
        int lineth;
};
bool isTheSameLine(int s1,int s2){
        for(set<int>::iterator it=stat[s1].begin();it!=stat[s1].end();it++){
                if(stat[s2].count(*it))return 1;
        }
        return 0;
}
long long ans(int s,int t){
        queue<dfsNode>q;
        for(set<int>::iterator it=stat[s].begin();it!=stat[s].end();it++){
                q.push({s,*it,0});
        }
}
int main(){
        cin>>n>>n>>m>>q>>q;
        for(int i=1;i<=m;i++){
                scanf("%d",penalty+i);
        }
        for(int i=1;i<=n;i++){
                scanf("%d",a+i);
                for(int j=1,a,t;j<=k[i];j++){
                        scanf("%d%d",&a,&t);
                        line[i].push_back(t);
                        trans[{a,i}]=t;
                        stat[a].insert(i);
                }
        }
        for(int i=1;i<=q;i++){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",ans(x,y));
        }
        return 0;
}
*/
