#include<bits/stdc++.h>
using namespace std;
constexpr int Maxn=1e6+5,Maxm=2e6+5;
int id,T,n,k,x1,x2,Dep[Maxn],Fa[Maxn],To[Maxm],Next[Maxm],Ne[Maxn],bnt=1,x,dad[Maxn],cnt,ans;
bitset<Maxn> b;
int Find(int x){
	if(dad[x])return dad[x]=Find(dad[x]);
	return x;
}
void Union(int x1,int x2){
	int f1=Find(x1);
	int f2=Find(x2);
	if(f1!=f2){
		dad[f1]=f2;
		cnt--;
	}
}
void Add(int x1,int x2){
	To[bnt]=x2;
	Next[bnt]=Ne[x1];
	Ne[x1]=bnt;
	bnt++;
}
void dfs(int x,int Last){
	int Now=Ne[x];
	Fa[x]=Last;
	while(Now){
		if(To[Now]==Last){
			Now=Next[Now];
			continue;
		}
		Dep[To[Now]]=Dep[x]+1;
		dfs(To[Now],x);
		Now=Next[Now];
	}
}
int d(int x,int y){
	if(x==y)return 0;
	if(Dep[x]>Dep[y])return d(Fa[x],y)+1;
	return d(x,Fa[y])+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>id>>T;
	while(T){
		T--;
		cin>>n>>k;
		bnt=1;
		for(int i=1; i<=n; i++)Ne[i]=0;
		for(int i=1; i<=n-1; i++){
			cin>>x1>>x2;
			Add(x1,x2);
			Add(x2,x1);
		}
		dfs(1,0);
		ans=n+1;
		for(int i=0; i<(1<<n); i++){
			x=0;
			for(int j=0; j<n; j++){
				if((1<<j)&i)x++;
				b[j+1]=dad[j+1]=0;
			}
			if(x!=k)continue;
			for(int j=0; j<n; j++){
				if((1<<j)&i)b[j+1]=1;
			}
			cnt=k;
			for(int i=1; i<=n; i++){
				if(b[i]&&b[Fa[i]])Union(i,Fa[i]);
			}
			if(cnt>2)continue;
			x1=0;
			for(int i=1; i<=n; i++){
				x=n+1;
				for(int j=1; j<=n; j++){
					if(!b[j])continue;
					x=min(x,d(i,j));
				}
				x1=max(x1,x);
			}
			ans=min(ans,x1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
longlong

±©Á¦ 
*/
