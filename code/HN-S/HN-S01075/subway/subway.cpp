#include <bits/stdc++.h>
#define int long long
using namespace std;
int readint(){
	int k=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c-'0');
	return f*k;
}
int c,n,m,d,q,chum[550000],luxian[550000],lujing[550000][22],lujingc[550000][22];
int mapp[1000][1000]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		int x,y;
		for(int i=1;i<=m;i++){
			chum[i]=readint();
		}
		for(int k=1;k<=500;k++){
			for(int i=1;i<=500;i++){
				if(mapp[i][k]==0) mapp[i][k]=1e16;
			}
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				x=readint();
				y=readint();
				luxian[x]++;
				lujing[x][luxian[x]]=i;
				lujingc[x][luxian[x]]=y;
				for(int o=1;o<luxian[x];o++){
					mapp[lujing[x][o]][i]=min(mapp[lujing[x][o]][i],y+lujingc[x][o]);
					mapp[i][lujing[x][o]]=min(mapp[i][lujing[x][o]],y+lujingc[x][o]);
				}
			}
		}
		for(int i=1;i<=n;i++) mapp[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j) mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[j][k]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			int ans=1e16;
			for(int o=1;o<=luxian[x];o++){
				for(int j=1;j<=luxian[y];j++){
					ans=min(ans,mapp[lujing[y][j]][lujing[x][o]]+lujingc[x][o]+lujingc[y][j]);
				}
			}
			cout<<ans+chum[x]+chum[y]<<endl;
		}
	return  0;
} 
/*
T1:45pts: baoli
100pts:双指针从左往右，可以发现具有线性性质，所以直接改ans
T2：考虑建边发现地铁站口与站厅可以看为点权 
然后地铁只有500个可以跑floyd 44pts+8pts特殊点 
*/
