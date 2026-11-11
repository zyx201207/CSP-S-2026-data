//16 18
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
vector<int> nbr[N];
int maxd,maxx,len[N],fa[N],a[N];
bool f[N];
void dfs(int cur,int fa,int dis,int faa[]){
	faa[cur]=fa;
	if(dis>maxd){
		maxd=dis;
		maxx=cur;
	}
	for(int nxt:nbr[cur]){
		if(nxt==fa){
			continue;
		}
		dfs(nxt,cur,dis+1,faa);
	}
	return;
}
void df2(int cur,int fai){
	len[cur]=1;
	for(int nxt:nbr[cur]){
		if(nxt==fai){
			continue;
		}
		df2(nxt,cur);
		if(!f[nxt]){
			cerr<<"^"<<nxt<<endl;
			len[cur]=max(len[cur],len[nxt]+1);
		}
	}
	cerr<<"%"<<cur<<" "<<len[cur]<<endl;
	return;
}
int c(int x,int y){
	return max(0ll,x-y);
}
int help(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		nbr[i].clear();
		len[i]=fa[i]=a[i]=f[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		nbr[u].push_back(v);
		nbr[v].push_back(u);
	}
	maxd=maxx=0;
	dfs(1,0,0,fa);
	int x=maxx;
	maxd=maxx=0;
	dfs(x,0,0,len);
	int y=maxx;
	cerr<<"$"<<x<<" "<<y<<endl;
	int ox=x,oy=y;
	while(x!=1){
		f[x]=true;
		x=fa[x];
	}
	while(y!=1){
		f[y]=true;
		y=fa[y];
	}
	x=ox;
	y=oy;
	f[1]=true;
	df2(1,0);
	int al=0;
	while(x!=1){
		a[++al]=len[x];
		x=fa[x];
	}
	a[++al]=len[1];
	int bl=al;
	while(y!=1){
		a[++bl]=len[y];
		y=fa[y];
	}
	for(int i=al+1,j=bl;i<j;i++,j--){
		swap(a[i],a[j]);
	}
	int sum=0;
	for(int i=1;i<=bl;i++){
		cerr<<"#"<<a[i]<<endl;
		sum+=a[i];
	}
	int d=sum/3,s1=0,s2=0,s3=0,s4=0,s5=0,cur=0;
	while(cur<=bl){
		cur++;
		s1+=a[cur];
		if(s1>d){
			s1-=a[cur];
			break;
		}
	}
	cerr<<"!"<<cur<<endl;
	s2=a[cur]-1;
	while(cur<=bl){
		cur++;
		s3+=a[cur];
		if(s3>=d){
			s3-=a[cur];
			break;
		}
	}
	cerr<<"@"<<cur<<endl;
	s4=a[cur]-1;
	while(cur<=bl){
		cur++;
		s5+=a[cur];
	}
	int lt=0,rt=n+1;
	while(lt+1<rt){
		int mid=(lt+rt)/2;
		if(c(s1,mid)+c(s2,mid)+c(s3,mid)+c(s4,mid)+c(s5,mid)<=k-2){
			rt=mid;
		}
		else{
			lt=mid;
		}
	}
	return rt;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<help()<<endl;
	}
	return 0;
}

