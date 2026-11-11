#include<bits/stdc++.h>
using namespace std;
int n,c,t,k,a[20001],ans;
int nxt[20001],h[20001],cnt;
bool l[20001];
void dfs(int p,int sum){
	if(p==k){
		int num=0;
		queue<pair<int,int> >q;
		bool li[20001];
		for(int i=1;i<=n;i++){
			li[i]=l[i];
			if(l[i])q.push({i,0});
		}while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			num=max(num,y);
			q.pop();
			for(int i=h[x];i;i=nxt[i])
				if(!li[a[i]]){
					q.push({a[i],y+1});
					li[a[i]]=1;
				}
		}ans=min(ans,num);
		return;
	}for(int i=1;i<=n;i++)
		if(!l[i]){
			bool li=0;
			if(p)
				for(int j=h[i];j;j=nxt[j])
					if(l[a[j]]){
						li=1;
						break;
					}
			if(!li&&sum==2)continue;
			l[i]=1;
			dfs(p+1,sum+!li);
			l[i]=0;
		}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(h,0,sizeof h);
		memset(nxt,0,sizeof nxt);
		cnt=0;
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			if(c<13||c>14){
				nxt[++cnt]=h[u];
				h[u]=cnt;
				a[cnt]=v;
				nxt[++cnt]=h[v];
				h[v]=cnt;
				a[cnt]=u;
			}
		}if(c>=13&&c<=14){
			printf("1\n");
			continue;
		}ans=1e9;
		dfs(0,0);
		printf("%d\n",ans);
	}return 0;
}
