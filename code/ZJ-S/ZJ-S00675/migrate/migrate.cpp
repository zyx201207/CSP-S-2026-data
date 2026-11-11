#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int p,dis;
	bool operator<(const node& cp)const{
		return dis>cp.dis;
	}
};
int c,t,n,d,a[2000006],cnt;
bool vis[2000006];
bool bfs(int sx,int sy){
	int res=0,minn=0x3f3f3f3f;
	vis[sx]=1;
	priority_queue<node>q;
	q.push((node){sx,0});
	while(q.size()){
		node p=q.top();
		//printf("dis:%d pos:%d\n",p.dis,p.p);
		q.pop();
		vis[p.p]=false;
		if(p.p==sy){
			if(!res){
				minn=p.dis;res++;//printf("the first dis:%d\n",minn,p.p);
			}else{
				if(p.dis==minn)res++;
				else break;
			}
		}if(p.dis>minn)break;
		for(int i=sy;i>=p.p+1;i--){
			if(a[i]-a[p.p]<=d){
				vis[i]=true;
				q.push((node){i,p.dis+1});
			}
		}
	}//printf("the dis of %d to %d is ended\n",sx,sy);
	if(res!=2)return false;
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		cnt=0;
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(bfs(i,j))cnt++;
				//printf("now the value of cnt is:%d\n",cnt);
			}
		}printf("%d\n",cnt);
	}
	return 0;
}
