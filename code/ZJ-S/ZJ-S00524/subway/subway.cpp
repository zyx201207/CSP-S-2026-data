#include<bits/stdc++.h>
#define ll long long
#define rd read()
using namespace std;

inline int read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void wt(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)wt(x/10),x%=10;
	putchar(x+48);
}
inline void wtln(int x){
	wt(x),putchar('\n');
}
const int N = 505;
int c,n,m,d,q,w[N],f[N][N],a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f3f3f,sizeof f);
	c=rd,n=rd,m=rd,d=rd,q=rd;
	for(int i=1;i<=m;i++)w[i]=rd;
	for(int i=1;i<=n;i++){
		int k=rd;
		for(int i=1;i<=k;i++)a[i]=rd,t[i]=rd;
		for(int i=1;i<k;i++){
			for(int j=i+1;j<=k;j++){
				f[a[i]][a[j]]=f[a[j]][a[i]]=min(f[a[i]][a[j]],t[i]+t[j]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x=rd,y=rd;
		wtln(w[x]+w[y]+f[x][y]);
	}
	return 0;
}
