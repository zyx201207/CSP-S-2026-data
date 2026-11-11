#include<bits/stdc++.h>
using namespace std;
struct S{
	int x,y,v,q,h;
}k[500005];
int c,n,m,d,p,w[500005],a[500005],b[500005],fa[500005],g,r;
bool cmp(S qq,S hh){
	return qq.x<hh.x;
}
int ge(int a){
	if(fa[a]==a)return a;
	else return fa[a]=ge(fa[a]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>w[i];
	while(n--){
		int s;
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=2;i<=s;i++){
			g++,k[g].x=a[i],k[g].y=a[i-1],k[g].v=0;
			k[g].q=b[i],k[g].h=b[i-1];
			g++,k[g].x=a[i-1],k[g].y=a[i],k[g].v=0;
			k[g].q=b[i-1],k[g].h=b[i];
		}
	}
	int h=g;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=h;j++){
			if(k[i].y==k[j].x&&k[i].x!=k[i].y)
				for(int t=1;t<=h;t++){
					if(k[t].x==k[j].x&&k[t].q==k[j].q){
						if(k[t].v==0)k[t].v=k[i].h+k[j].q;
						else g++,k[g].h=k[t].h,k[g].q=k[t].q,k[g].x=k[t].x,k[g].y=k[t].y,k[t].v=k[i].h+k[j].q;
					}
				}
		}
	}
	sort(k+1,k+1+g,cmp);
	while(p--){
		int l,r,ans=0,mar;
		cin>>l>>r;
		mar=l;
		for(int i=1;i<=m;i++)fa[i]=i;
		for(int i=1;i<=g;i++){
			if(mar==k[i].x){
				int x=ge(k[i].x);
				int y=ge(k[i].y);
				if(x!=y)fa[x]=y;
				mar=k[i].y;
				ans+=k[i].v;
			}
			if(mar==r)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
