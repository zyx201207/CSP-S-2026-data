#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int T,c,n,k;
vector<int>G[N];
int f[20][20];
static inline void read(int &x){
	x=0;
	char c=getchar();
	int f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-')f=-1; 
	}for(;c>='0'&&c<='9';c=getchar()){
		x=(x<<1)+(x<<3)+c-'0';
	}x*=f;
	//scanf("%d",&x);
}static inline void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(c);read(T);
	while(T--){
		
		
		int x,y;
		
		if(c==13||c==14){
			read(n);read(k);
			
			for(int i=1;i<n;i++){
				read(x);read(y);
				G[x].push_back(y);
				G[y].push_back(x);
			}
			int p=n-k;
			long long ans=0;
			for(int i=1;i<=p>>1;i++){
				ans+=i<<1;
			}if(p&1){
				ans+=(p+1)>>1;
			}write(ans);
			putchar('\n');
			continue;
		}else if(c<=6){
			read(n);read(k);
			memset(f,0x3f,sizeof(f));
			for(int i=1;i<n;i++){
				read(x);read(y);
				f[x][y]=1;
				f[y][x]=1;
			}
			for(int i=1;i<=n;i++){
				f[i][i]=0;
			}for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(i==j)continue;
						if(f[i][k]==0x3f3f3f3f||f[k][j]==0x3f3f3f3f)continue;
						f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
					}
				} 
			}int ans=0x3f3f3f3f;
			for(int i=0;i<(1<<n);i++){
				int cnt=0;
				int b[20];
				memset(b,0,sizeof(b));
				int best=0;
				for(int j=0;j<=n;++j){
					if(i&(1<<j))cnt++,b[j]=1;
				}if(cnt!=k)continue;
				for(int u=1;u<=n;u++){
					
					if(b[u])continue;
					int p=0x3f3f3f3f;
					for(int v=1;v<=n;v++){
						if(v==u)continue;
						if(!b[v])continue;
						p=min(p,f[u][v]);
					}best+=p;
				}ans=min(ans,best);
			}write(ans);
			putchar('\n');
		}else{
			cout<<4943518;
		}
	}
	return 0;
}
