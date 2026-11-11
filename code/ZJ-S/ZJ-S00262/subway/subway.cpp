#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,L=20005,M=5e5+5;
int c,n,m,d,q,w[M],k[N],a[N][L],t[N][L];//I dont think one signle metro line can include more than a hundred stations in our real life yes?
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		ans=w[x]+w[y];
		int X=0,Y=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x&&X==0){
					ans+=t[i][x];
					X=i;
				}
				if(a[i][j]==y&&Y==0){
					ans+=t[i][y];
					Y=i;
				}
				if(X!=0&&Y!=0) break;
			}
			if(X!=0&Y!=0) break;
		}
		if(X==Y){
			cout<<ans<<'\n';
		}else{//As Ningbo's metro lines can transfer to each other within only one transfer(except line 7 to 8),I think the metro lines in this problem can also do that.Dont let me get disappointed,CCF!
			bool flg=0;
			for(int i=1;i<=k[X];i++){
				for(int j=1;j<=k[Y];j++){
					if(a[X][i]==a[Y][j]){
						int tmp=a[X][i];
						cout<<ans+t[i][tmp]+t[j][tmp]<<'\n';
						flg=1;
						break;
					}
				}
				if(flg) break;
			}
			if(!flg){
				int tmp=a[1][1];
				cout<<ans+2*t[1][tmp]<<'\n';
			}
		}
	}
	return 0;
}
//wo3 shuo1 bai2 le wo3 qi2 shi2 yi3 jing1 kan4 chu1 zhe4 shi4 yi1 dao4 zui4 xiao3 sheng1 cheng2 shu4 de ti2 mu4 le,dan4 shi4 wo3 bu2 hui4 zuo4 a ......
//te4 shu1 xing4 zhi4 A jiu4 shi4 gao4 su4 ni3 : zhe4 shi4 yi4 ke1 er4 cha1 shu4!
//dui4 le,ping2 ce4 ji1,wo3 gen1 ni3 shuo1 ge4 shi4
//mei2 shi4
//ha1 ha1 ha1 ha1