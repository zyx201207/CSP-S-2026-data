#include<bits/stdc++.h>//考试策略错了，T3花了太多时间了，难以得分，0pts 
#define int long long
using namespace std;
inline int read(){
	int x(0),sign(1);
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			sign=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-'0'; 
	}
	return x*sign;
}
int c,t;
int n,d;
int a[2000005];
int dpdis[5005][5005];//dpdis[i][j]表示i到j的最短距离
int dpcnt[5005][5005];//表示方式个数
namespace sub10_25{
	void work(){
		a[n+1]=1e14;
		for(int i=1;i<=n+1;++i){
			for(int j=i+1;j<=n+1;++j){
				dpdis[i][j]=1e18;
				dpcnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i){
			dpdis[i][i]=0;
			dpcnt[i][i]=1;
		}
		int ans=0;
		for(int i=n-1;i>=1;--i){
			int cango=i,num=0;//cango:最极限能到的,num:距离 
			int l,r;
			for(int j=i+1;j<=n;++j){
				if(a[cango]+d>=a[j]){
					dpdis[i][j]=dpdis[i][cango]+1;
					dpcnt[i][j]=max(dpcnt[cango][j],1ll);
//					cout<<"sp,cango="<<cango<<' '<<endl;
//					cout<<i<<' '<<j<<' '<<dpdis[i][j]<<' '<<dpcnt[i][j]<<endl;
					continue;
				}
				while(dpdis[cango][j]==1e18){
					cango++;
				}
//				cout<<"cango="<<cango<<endl;
				if(dpdis[i][cango]==1e18){
//					cout<<i<<' '<<j<<"can't"<<endl; 
					break;
				}
				l=cango;//l是最早能到的 
				while(a[i]+d>=a[cango+1]&&dpdis[i][cango]==dpdis[i][cango+1]){
					cango++;
//					cout<<"cangonow++"<<endl;
				}
				r=cango;
//				cout<<"l,r="<<l<<' '<<r<<endl;
				dpdis[i][j]=dpdis[cango][j]+1;
				dpcnt[i][j]=0;
				for(int k=l;k<=r;++k){
					dpcnt[i][j]+=dpcnt[k][j];
				}
//				cout<<i<<' '<<j<<' '<<dpdis[i][j]<<' '<<dpcnt[i][j]<<endl;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(dpcnt[i][j]==2){
//					cout<<i<<' '<<j<<" ans++"<<endl;
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		if(n<=5000){
			sub10_25::work();
		}
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 1
5 3
-3 0 2 3 4
*/
