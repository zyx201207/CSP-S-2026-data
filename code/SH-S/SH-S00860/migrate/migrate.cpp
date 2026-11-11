#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
typedef long long ll;
#define pii pair<int,int>
#define mk make_pair
int c,t;
ll x[N];
int dx[N]; //从x出发，往后最多飞到哪个岛屿 
int n;
ll d,ans=0; 

ll read(){
	ll f=1,res=0;
	char ch=getchar();
	while(ch!='-' && (ch>'9'||ch<'0'))ch=getchar();
	if(ch=='-')f=-1;
	while(ch>='0' && ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return f*res;
}

inline void init(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
			memset(x,0,sizeof(x));
//			printf("?");
			init();
//			for(int i=1;i<=n;i++)printf("%d ",x[i]);
			ans=0;
			int dx=x[2]-x[1];
			if(dx==0){
				printf("0\n");
				continue;
			}
			int stp=d/dx;
			for(int i=1;i<=n;i++){
				int j=i+stp*2-1;
				if(j<=n)ans++;
			}
			printf("%d\n",ans);
		}
	return 0;
}
