#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T,n,d,pos[N],pre[N],k,mxpos,g,mndis;
int r[N];
struct node{
	int from,to,ne,len;
}a[N];
typedef pair<int,int> PI;
priority_queue<PI,vector<PI>,greater<PI> >q;
typedef pair<int,pair<int,int> > PII;
priority_queue<PII,vector<PII>,greater<PII> >qq;
bool f[N];
void add(int x,int y,int w){
	a[++k]={x,y,pre[x],w};
	pre[x]=k;
}
void biaoji(int s,int t){
	while(!qq.empty())qq.pop();
	qq.push({0,{s,1}});
	r[1]=s;
	while(!qq.empty()){
		int h=qq.top().second.first,dis=qq.top().first,idx=qq.top().second.second;
		qq.pop();
		if(h==t){
			if(mndis==dis){
				for(int i=1;i<=idx;i++)f[r[i]]=1;
			}
			return;
		}
		for(int i=pre[h];i;i=a[i].ne){
			int to=a[i].to;
			r[idx+1]=to;
			qq.push({dis+a[i].len,{to,idx+1}});
		}
	}
}
bool dij(int s,int t){
	while(!q.empty())q.pop();
	q.push({0,s});
	mndis=INT_MAX;
	int cnt=0;
	while(!q.empty()){
		int h=q.top().second,dis=q.top().first;
		q.pop();
		if(dis>mndis)continue;
		if(h==t){
			if(mndis==INT_MAX){
				mndis=dis;cnt++;
			}
			else if(mndis==dis)cnt++;
		}
		for(int i=pre[h];i;i=a[i].ne){
			int to=a[i].to;
			q.push({dis+a[i].len,to});
		}
	}
	if(cnt==2)return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
			mxpos=max(mxpos,pos[i]-pos[i-1]);
			for(int j=i-1;j>=1;j--){
				if((pos[i]-pos[j])<=d)add(j,i,pos[i]-pos[j]);
			}
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			if(f[i])continue;
			for(int j=n;j>i;j--){
				if(f[j])continue;
//				if(pos[j]-pos[i]()<=d)continue;
				if(dij(i,j)){
					cnt++;
					biaoji(i,j);
//					cout<<i<<" "<<j<<"\n";
					break;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
