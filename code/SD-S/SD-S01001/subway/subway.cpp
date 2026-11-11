#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char c;
	int re=0,f=1;
	while (1){
		c=getchar();
		if ('0'<=c and c<='9')	break;
		if (c=='-'){
			f=-1;c='0';
			break;
		}
	}
	while (1){
		re=re*10+c-'0';
		c=getchar();
		if (!('0'<=c and c<='9'))	return re*f;
	}
}
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int minsiz[N][N];
bool flag[N][N];
int a[N][N],t[N][N],k[N];
int stk[M][25],stk2[M][25];
int cnt[M];
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	memset(minsiz,63,sizeof(minsiz));
	for (int i=1;i<=m;i++)	w[i]=read();
	for (int i=1;i<=n;i++){
		minsiz[i][i]=0;
		k[i]=read();
		for (int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read();
			for (int w=1;w<=cnt[a[i][j]];w++){
				minsiz[i][stk[a[i][j]][w]]=minsiz[stk[a[i][j]][w]][i]=min(minsiz[i][stk[a[i][j]][w]],stk2[a[i][j]][w]+t[i][j]);
			}
			stk2[a[i][j]][++cnt[a[i][j]]]=t[i][j],stk[a[i][j]][cnt[a[i][j]]]=i;
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			if (minsiz[i][j]==minsiz[N-1][N-1])	cout<<setw(3)<<"X";
//			else cout<<setw(3)<<minsiz[i][j];
//		}
//		cout<<"a\n";
//	}
	for (int i=1;i<=n;i++){
		int k=i,kkk=0;
		flag[i][i]=1;
		for (int z=i;z<=n;z++){
			kkk=n+1;
			for (int j=i+1;j<=n;j++)
				if (!flag[i][j]){
//					cout<<i<<" "<<j<<" "<<k<<"\n";
					minsiz[i][j]=minsiz[j][i]=min(minsiz[i][j],minsiz[i][k]+minsiz[k][j]);
					if (minsiz[i][j]<minsiz[i][kkk])	kkk=j;
				}
			k=kkk;
			flag[i][kkk]=1;
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			if (minsiz[i][j]==minsiz[N-1][N-1])	cout<<setw(3)<<"X";
//			else cout<<setw(3)<<minsiz[i][j];
//		}
//		cout<<"\n";
//	}
	while (q--){
		int x=read(),y=read();
		int ans=4e18;
		for (int i=1;i<=cnt[x];i++)
			for (int j=1;j<=cnt[y];j++)
				ans=min(ans,minsiz[stk[x][i]][stk[y][j]]+stk2[x][i]+stk2[y][j]);
		cout<<w[x]+w[y]+ans<<"\n";
	}
}

