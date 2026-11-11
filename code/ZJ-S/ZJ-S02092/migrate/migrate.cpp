#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005;
int c,t;int n,d;int x[maxn],ans;
struct point{
	int id;int l;vector<int>v;
}a[maxn];
void explore(int i){
	int dis[maxn],T[maxn];bool vis[maxn];
	memset(dis,0xff,sizeof dis);memset(vis,0,sizeof vis);
	queue<int>q;q.push(i);
	while(!q.empty()){
		int f=q.front();q.pop();vis[f]=1;
		for(int i=0;i<a[f].l;i++){
			if(vis[f]&&dis[a[f].v[i]]==dis[f]+1)T[a[f].v[i]]++;
			if(!vis[a[f].v[i]]&&dis[a[f].v[i]]>dis[f]+1){
				dis[a[f].v[i]]=dis[f]+1;
				q.push(a[f].v[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(T[i]==1)ans++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<n;i++){cin>>x[i];a[i].id=i;}
		for(int i=n-1;i>0;i--){
			for(int j=1;i+j<=n;j--){
				if(d>=x[i+j]-x[j]){
					a[i+j].l++;a[i+j].v.push_back(j);
					a[j].l++;a[j].v.push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			explore(i);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
