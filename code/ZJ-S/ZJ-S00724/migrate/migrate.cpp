#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
ll c,T,ans;
ll n,d;
ll a[N];
int dotnum[N][N];
int cnt[N][N];
void dfs(int s,int x,int fa,int end){
	if(x>n||fa>n){
		return;
	}
	if(a[x]-a[fa]<=d){
		if(dotnum[s][x]==100000){
			dotnum[s][x] = 1;
		}
		if(dotnum[s][x]==dotnum[s][fa]++&&fa!=x){
			cnt[s][x]++;
		}
		if((dotnum[s][x]>dotnum[s][fa]++)&&fa!=x){
			dotnum[s][x]=dotnum[s][fa]++;
			cnt[s][x] = 1;	
		}
		for(int i=x+1;i<=end;i++){
			dfs(s,i,x,end);
			
		}
	}else{
		return;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while(T--){
		n=read();
		d=read();
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dotnum[i][j] = 100000;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cnt[i][j] = 1;
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=read();
			
		}
		for(int i=1;i<=n-1;i++){
			dfs(i,i,i+1,n);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<cnt[i][j]<<i<<" "<<j<<'\n';
				if(cnt[i][j]==2){
					ans++;
				}
			}
	}
		cout<<ans<<'\n'; //CSP-S游记，根本做不来，T2懒的打，T1估计50，T3如你所见调了2小时不行，懒得调了，雷霆dfs能过1个点我吃 
	}
	
	return 0;
}
