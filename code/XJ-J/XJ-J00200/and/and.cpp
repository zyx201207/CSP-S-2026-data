#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
node d[200005];
long long a[200005],n,m,maxx=-2,b[200005],c[200005],ans=0;
vector <long long> g[200005];
bool cmp(node l,node r){
	if(l.y==r.y){
		return l.x>r.x;
	}
	return l.y>r.y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long p=a[i],u=0,v=0;
		while(p){
			p=p/2;
			u++;
		}
		p=a[i];
		while(p){
			if(p%2==1){
				g[i].push_back(u-v);
				v++;
			}
			p=p/2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			b[g[i][j]]++;
			maxx=max(maxx,g[i][j]);
		}
	}
	int res;
	for(int i=maxx;i>=1;i--){
		if(b[i]>=m){
			res=i;
			break;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(g[i][j]==res){
				cnt++;
				c[cnt]=a[i];
				d[cnt].x=a[i];
				d[cnt].y=g[i].size()-j;
			}
		}
	}
	sort(d+1,d+cnt+1,cmp);
	ans=d[1].x;
	for(int i=1;i<=m;i++){
		ans=ans&d[i].x;
	} 
	cout<<ans;
	return 0;
} 
