#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+5,M=5e3+5;
const ll inf=1e18;
int Type,T,n,nxt[25][N],lst[25][N];
ll d,x[N],dis[M][M];
ll read(){
	ll res=0;bool f=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=1,c=getchar();
	while(isdigit(c)) res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return (f?-res:res);
}
bool check(int x,int y){
	ll sum1=x+y,sum2=x+y;
	int u=x,v=y;
	while(nxt[0][u]<y){
		if(nxt[0][u]==u) return 0;
		u=nxt[0][u];
		sum1+=u;
	}
	while(lst[0][v]>x){
		if(lst[0][v]==v) return 0;
		v=lst[0][v];
		sum2+=v;
	}
	return sum1==sum2+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Type=read(),T=read();
	while(T--){
		ll ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		for(int l=1,r=1;l<=n;l++){
			while(r+1<=n&&x[r+1]-x[l]<=d) r++;
			nxt[0][l]=r;
		}
		for(int r=n,l=n;r>=1;r--){
			while(l-1>=1&&x[r]-x[l-1]<=d) l--;
			lst[0][r]=l;
		}
//		for(int j=1;j<=25;j++)
//			for(int i=1;i<=n;i++)
//				lst[j][i]=lst[j-1][lst[j-1][i]],
//				nxt[j][i]=lst[j-1][lst[j-1][i]];
//		for(int i=1;i<n;i++){
//			if(lst[i]==i||nxt[i+1]==i+1) continue;
//			ans+=1ll*(sum1[nxt[i]]+cnt2[i])*(sum2[lst[i+1]]+cnt1[i+1]);
//			cout<<i<<" "<<sum1[nxt[i+1]]<<" "<<cnt2[i]<<" "<<sum2[lst[i]]<<" "<<cnt1[i+1]<<" "<<ans<<endl;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				ans+=check(i,j);
//			}
//		}
		for(int i=1;i<=n;i++){
			int w=i;
			ll sum=i;
			for(int j=i+1;j<=n;j++){
				if(nxt[0][w]==w) break;
				if(j==nxt[0][w]){
					sum+=j;
					w=nxt[0][w];
					dis[i][j]=sum;
				}
				else dis[i][j]=sum+j;
			}
		}
		for(int i=1;i<=n;i++){
			int w=i;
			ll sum=i;
			for(int j=i-1;j>=1;j--){
				if(lst[0][w]==w) break;
				if(j==lst[0][w]){
					sum+=j;
					w=lst[0][w];
					dis[i][j]=sum;
				}
				else dis[i][j]=sum+j;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dis[i][j]&&dis[j][i]&&dis[i][j]==dis[j][i]+1)
					ans++;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				ans+=check(i,j);
//			}
//		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7
*/
