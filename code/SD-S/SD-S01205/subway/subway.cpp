#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10,N=510;
int w[M],cnt[M];
pair<int,int>g[M][20];
int a[N][N];
int read(){
	char c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	int ans=0;
	while('0'<=c&&c<='9')ans*=10,ans+=c-'0',c=getchar();
	return ans;
}
void write(int x){
	if(x==0)return (void)putchar('0');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
    	int k;
    	k=read();
    	while(k--){
    		int a,t;
    		a=read(),t=read();
    		g[a][cnt[a]++]={i,t};
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		for(auto j:g[i]){
			for(auto k:g[i]){
				int x=k.first,y=j.first,w=j.second+k.second;
				if(x==y)continue;
				a[x][y]=min(w,a[x][y]);
				a[y][x]=a[x][y];
			}
		}
	}
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		x=read(),y=read();
		int ans=1e18;
		for(auto ji=0;ji<cnt[x];ji++){
			auto j=g[x][ji];
			for(auto ki=0;ki<cnt[y];ki++){
				auto k=g[y][ki];
				ans=min(ans,a[j.first][k.first]+w[x]+w[y]+j.second+k.second);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
//嘻嘻爱抚你出的题无疑是简单的 
//不是我旁边也在写注释，但显然他不是对耶
//他不会是看见了我写注释也要抒发一下感情吧 




//我去他在默写歌词 
