#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
deque<int> q;
int n,m,a[200005],ans[300005];
bool vis[300005];
int main(){
	bool flag=0;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i])
			flag=1;
	}
	if(!flag)
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
	else
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			for(int j=i;j<=n;j++){
				if(!vis[a[j]])
					q.push_back(a[j]),vis[a[j]]=1;
				else{
					while(!q.empty()){
						if(q.back()==a[j]){
							q.pop_back();
							break;
						}
						vis[q.back()]=0;
						q.pop_back();
					}
					q.push_back(a[j]);
				}
			}
			while(!q.empty()){
				ans[q.front()]++;
				q.pop_front();
			}
		}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
