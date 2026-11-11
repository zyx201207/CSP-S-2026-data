#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100010;
int c,t;
int n,k,que[N],f[N],ql,qr;
int id[N];
vector<int> edge[N];
int ht[2];
int bfs(int h,int fi){
	int ql=1,qr=1;
	que[qr]=fi,f[qr]=0;
	qr+=1;
	while(qr!=n+1){
		int u=que[ql];
		++ql;
		for(int i=1;i<=edge[u].size();++i){
			int v=edge[u][i];
			if(v!=f[u]){
				que[qr]=v,f[qr]=u;
				++qr;
			}
		}
	}
}
int ml[N];
int getml(int u,int fa){
	for(int i=1;i<=edge[u].size();++i){
		int v=edge[u][i];
		if(v!=fa){
			getml(v,fa);
			ml[u]=max(ml[u],ml[v]+1);
		}
	}
}

int mxr[N],mxl[N],len;

int check(int dis){
	int c=0;
	for(int i=1;i<=len;++i){
		if(mxl[id[i]]>dis)
			c+=mxl[id[i]]-dis-1;
	}
	if(c>k)
		return 0;
	for(int i=1;i<=len;++i)
		mxl[i]=max(mxl[i-1],i-(dis+1-ml[id[i]]));
	for(int i=len;i;--i)
		mxr[i]=min(mxr[i+1],i+dis+1-ml[id[i]]);
	int l=1,r=len;
	while(r!=l){
		int mid=(l+r)/2;
		int lp=mxl[mid]-dis,rp=len-dis-mxr[mid+1];
		if(max(1,lp)>max(1,rp))
			l=mid;
		else
			r=mid;
	}
	return mxl[l]-dis+len-dis-mxr[r]+l<=k-c;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int u,v;
	while(--t){
		cin>>n>>k;
		for(int i=1;i<n-1;++i){
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
	}
	
	bfs(0,1);
	bfs(1,ht[0]);
	len=0;
	for(int i=ht[1];i;i=f[i])
		id[++len]=1;
	for(int i=1;i<=len;++i){
		int u=id[i];
		for(int i=1;i<=edge[u].size();++i){
			int v=edge[u][i];
			if(v!=i && v!=f[u]){
				getml(v,f[u]);
			}
		} 
	}
	int l=0,r=len/2;
	while(l!=r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0; 
}
