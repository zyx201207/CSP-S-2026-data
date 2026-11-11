#include<bits/stdc++.h>
using namespace std;
int n,a[505],e,m,ee,q,x[500005],y[500005],k,l,c[505],cnt,s[505],d[505],w,vis[505];
struct ll{
	int u,v,sum;
};
ll b[100005];
void add(int u,int v,int sum){
	b[++cnt].u=v;
	b[cnt].v=sum;
	b[cnt].sum=c[u];
	c[u]=cnt;
}
void sf(int z){
	if(w>=z*2+1){
		if(s[d[z*2]]<s[d[z*2+1]]){
			d[z]=d[z*2];
			sf(z*2);
		}else{
			d[z]=d[z*2+1];
			sf(z*2+1);
		}
	}else if(w>=z*2)d[z]=d[z*2];
}
void xc(int z){
	if(z/2>0){
		if(s[d[z/2]]>s[z]){
			swap(d[z/2],d[z]);
			xc(z/2);
		}
	} 
}
void di(int z){
	for(int i=1;i<=m;i++)s[i]=1e9;
	s[z]=0;
	d[1]=z;
	w=1;
	while(w>0){
		int u=d[1];
		vis[u]=0;
		sf(1);
		w--;
		for(int i=c[u];i;i=b[i].sum){
			int v=b[i].u,sum=b[i].v;
			if(s[u]+sum<s[v]){
				s[v]=s[u]+sum;
				if(vis[v]==0){
					d[++w]=v;
					vis[v]=1;
					xc(w);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>e>>n>>m>>ee>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k!=2)l=1;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>y[j];
			for(int k=1;k<j;k++){
				add(x[j],x[k],y[j]+y[k]);
				add(x[k],x[j],y[j]+y[k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		di(x[i]);
		cout<<s[y[i]]+a[x[i]]+a[y[i]]<<endl;
	}
	return 0;
}