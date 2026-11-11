#include<bits/stdc++.h>
using namespace std;
int n,c,t,f[25005],vis[25005],su[25005],ecnt,head[25005];
long long d,x[2000005];
struct nod{
	int l,r;
}shu[25005];
struct no{
	int next,to,w;
}a[200005];
void init(int u,int l,int r){
	shu[u]={l,r};
	if(l==r){
//		cout<<u+n<<" "<<l<<'\n';
		a[++ecnt]={head[u+n],l,0};
		head[u+n]=ecnt;
		return ;
	}
	int mid=l+r>>1;
	init(u<<1,l,mid);
	init(u<<1|1,mid+1,r);
	a[++ecnt]={head[u+n],(u<<1)+n,0};
	head[u+n]=ecnt;
	a[++ecnt]={head[u+n],(u<<1|1)+n,0};
	head[u+n]=ecnt;
//	cout<<u+n<<" "<<(u<<1)+n<<'\n';
//	cout<<u+n<<" "<<(u<<1|1)+n<<'\n';
}
void modify(int u,int l,int r,int x){
	int ll=shu[u].l,rr=shu[u].r,mid=ll+rr>>1;
	if(l<=ll&&rr<=r){
//		cout<<x<<" "<<n+u<<'\n';
		a[++ecnt]={head[x],n+u,1};
		head[x]=ecnt;
		return ;
	}
	if(l<=mid){
		modify(u<<1,l,r,x);
	}
	if(mid+1<=r){
		modify(u<<1|1,l,r,x);
	}
}
struct node{
	int u,w,op;
	friend bool operator<(node x,node y){
		int xx=x.u,yy=y.u;
		if(xx<=n)xx+=1e9;
		if(yy<=n)yy+=1e9;
		return x.w>y.w||x.w==y.w&&x.op>y.op||x.w==y.w&&x.op==y.op&&xx>yy;
	} 
};
priority_queue<node> q;
void dij(int u){
	q.push({u,0,0});
	memset(f,0x3f,sizeof f);
	memset(su,0,sizeof su);
	memset(vis,0,sizeof vis);
	f[u]=0;
	su[u]=1;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
//		cout<<u<<" "<<f[u]<<" "<<su[u]<<'\n';
		for(int i=head[u];i;i=a[i].next){
			if(f[a[i].to]==f[0]){
				su[a[i].to]=su[u];
				f[a[i].to]=f[u]+a[i].w;
				q.push({a[i].to,f[a[i].to],a[i].w});
			}
			else{
				if(f[u]+a[i].w<f[a[i].to]){
					f[a[i].to]=f[u]+a[i].w;
					su[a[i].to]=su[u];
					q.push({a[i].to,f[a[i].to],a[i].w});
				}
				else if(f[u]+a[i].w==f[a[i].to]){
					su[a[i].to]+=su[u];
					if(su[a[i].to]>=1e8)su[a[i].to]=(int)1e8; 
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			if(n==1){
				cout<<0<<'\n';
				continue;
			} 
			long long dd=x[2]-x[1];
			if(dd>d){
				cout<<0<<'\n';
				continue;
			}
			long long c=d/dd;
			if(c==1){
				cout<<0<<'\n';
				continue;
			}
//			cout<<c<<'\n';
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(i>=2ll*c){
					ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ecnt=0;
		for(int i=1;i<=5*n;i++){
			head[i]=0;
		}
		if(c<=6){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(abs(x[i]-x[j])<=d){
						a[++ecnt]={head[i],j,1};
						head[i]=ecnt;
					}
				}
			}
		}
		else{
			init(1,1,n);
			for(int i=1;i<=n;i++){
				int l=1,r=i-1,mid,cnt=-1;
				while(l<=r){
					mid=l+r>>1;
					if(x[i]-x[mid]<=d){
						r=mid-1;
						cnt=mid;
					}
					else{
						l=mid+1;
					}
				}
	//			cout<<cnt<<'\n';
				if(cnt!=-1){
					modify(1,cnt,i-1,i);
				}
				l=i+1,r=n,cnt=-1;
				while(l<=r){
					mid=l+r>>1;
					if(x[mid]-x[i]<=d){
						l=mid+1;
						cnt=mid;
					}
					else{
						r=mid-1;
					}
				}
	//			cout<<cnt<<'\n';
				if(cnt!=-1){
					modify(1,i+1,cnt,i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				if(su[j]==2)ans++;
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}

