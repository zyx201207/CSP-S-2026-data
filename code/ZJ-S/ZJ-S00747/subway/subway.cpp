#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[2000050],vis[2000050],ans;
struct e{
	int a[2000],t[2000],k;	
}a[2000];
struct node{
	int x,p;	
};
void f(int x,int y){
	queue<node> q;
	node now={x,w[x]};
	q.push(now);
	while(!q.empty()){
		node p=q.front();
		q.pop();
		if(p.x==y)ans=min(ans,p.p+w[y]);
		vis[x]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].k;j++){
				if(a[i].a[j]==x){
					for(int k=1;k<=a[i].k;k++){
						if(vis[a[i].a[k]]==false){
							vis[a[i].a[k]]=true;
							node now={a[i].a[k],p.p+a[j].t[k]+a[k].t[k]};
							q.push(now);
						}
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		cin>>a[j].k;
		for(int i=1;i<=a[j].k;i++){
			cin>>a[j].a[i]>>a[j].t[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=0x3f3f3f;
		f(x,y);
		cout<<ans<<endl;
	}
	return 0;
}	