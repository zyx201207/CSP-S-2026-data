#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,d,ans;
int a[N],l[N],r[N];
int R[N];
int cnt0[N],cnt1[N];
int f[N][2][4][3];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cid=read(),T=read();
	while(T--){
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		r[n]=n;int lst=n;
		for(int i=n-1;i>=1;i--){
			while(a[lst]-a[i]>d)lst--;
			r[i]=lst;
		}
		lst=1;l[1]=1;
		for(int i=2;i<=n;i++){
			while(a[i]-a[lst]>d)lst++;
			l[i]=lst;
		}
		for(int i=1;i<=n;i++)memset(f[i],0,sizeof f[i]);
		for(int i=n;i>=1;i--){
			if(r[i]==i)continue;
			for(int z:{0,1})
			for(int x:{0,1,2,3})
			for(int y:{0,1,2}){
				int cnt0=0,cnt1=0;
				//calc cnt0,cnt1
				if(r[i]!=i)cnt1+=(r[i]-i);
				if(x!=3){
					cnt1-=(r[i-1]-i);
					cnt0+=(r[i-1]-i);
					if(z!=0)cnt0-=(r[i-2]-i);
				}
				//calc f
				f[i][z][x][y]+=cnt0*(x+y==0);
				f[i][z][x][y]+=cnt1*(y==1);
				int nxtx=0,nxty=0,nxtz=(r[i]>i+2);
				int L0=l[r[i]-1],L1=l[r[i]];
				
				if(x!=3 && L1<=i-1)nxty+=x+1;
				if(z && L1<=i-2)nxty+=3;
				nxty+=y;if(nxty>=2)nxty=2;
				
				if(r[i]>i+1){
					if(x!=3 && L0<=i-1)nxtx+=x+1;
					if(z && L0<=i-2)nxtx+=3;
					nxtx+=y;if(nxtx>=2)nxtx=2;
				}else nxtx=3;
				
				f[i][z][x][y]+=f[r[i]][nxtz][nxtx][nxty];
			}
			ans+=f[i][0][3][0];
		}
		write(ans);putchar('\n');
	}
	return 0;
}
