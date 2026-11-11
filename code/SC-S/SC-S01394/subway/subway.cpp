#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long c,n,m,d,q;//测试点编号 地铁线路数 地铁站数 每个站最多d条经过 出行计划数
long long w[N];
long long f[2005][2005];
long long st[N],en[N];
long long k[N];
long long a[N][20005],t[N][20005];
long long read(){
	long long ans=0;
	char x;
	x=getchar();
	while(x>='0'&&x<='9'){
		ans=ans*10+x-'0';
		x=getchar();
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	//========输入=========
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){w[i]=read();}//每站地铁出战时间
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read(),t[i][j]=read();
		}
	}
	for(int i=1;i<=q;i++){
		st[i]=read(),en[i]=read();
	}
	//=======建边========= 
	//暴力n*n的建边
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int z=1;z<=k[i];z++){
				int x=a[i][j],y=a[i][z];
				f[x][y]=f[y][x]=min(f[x][y],t[i][j]+t[i][z]);			
			}
		}
	} 
	//=======特判 A=======
	//此时的隐藏条件是 m<=1000 此时m^3的fly也随便跑 
	//=====floyd==========
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	} 
	for(int i=1;i<=q;i++){
		cout<<w[st[i]]+w[en[i]]+f[st[i]][en[i]]<<"\n";
	}
	return 0;
}
