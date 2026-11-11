#include<bits/stdc++.h>
using namespace std;
#define int long long 
//#define lowbit(x) ((x)&(-(x)))
//#define pnt pair<int,int> 
bool MS;
int f[2000006][4];
int g[2000006][3],h[2000006];
int R[2000006],x[2000006],d;
void solve(){
	int n;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		int id=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		R[i]=id;
	}
	for(int i=n;i>=1;i--){
		if(R[i]==i){
			g[i][0]=0;
			if(i>=2)g[i][1]=0;
		}else if(R[i]==i+1){
			g[i][0]=g[R[i]][0]+1;
			if(i>=2){
				if(R[i]!=R[i-1])g[i][1]=g[R[i]][0]+1;
				else g[i][1]=0;
			}
		}else{
			g[i][0]=g[R[i]][1]+R[i]-i;
			if(i>=2&&R[i-1]>=i){
				if(R[i]!=R[i-1])g[i][1]=g[R[i]][1]+(R[i]-R[i-1]);
				else g[i][1]=0;
//		if(i==6)printf("%lld\n",g[6][1]);
			}else if(R[i-1]<i)g[i][1]=g[R[i]][1]+R[i]-i;
		}
	}
	for(int i=n;i>=1;i--){
//		if(i==4){
//			printf("%d----\n",R[i]);
//		}
		if(i>=2&&R[i-1]>=i){
			if(R[i]==i||R[i]==R[i-1]){
				h[i]=0;
			}else if(R[i]==i+1){
				if(R[i-1]!=i+1)h[i]=f[R[i]][0];
				else h[i]=0;
//				if(i==5){
//					printf("%lld %lld \n",R[i],R[i-1]);
//				}
//				if(i==5)puts("-----");
			}else if(R[i-1]+1==R[i]){
				h[i]=h[R[i]];
			}else {
				h[i]=f[R[i]][min(R[i]-i-1,2ll)];
			}
//			if(i==5){
//				printf("%lld %lld\n",f[6][0],R[i-1]);
//			}
		}
		if(R[i]==i){
			f[i][0]=0;
			if(i>=2)f[i][1]=0;
			if(i>=3)f[i][2]=0;
		}else if(R[i]==i+1){
			f[i][0]=f[R[i]][0];
			if(i>=2){
				if(R[i-1]!=R[i])f[i][1]=f[R[i]][0];
				else f[i][1]=g[R[i]][0]+1;
//			if(i==3)printf("%lld %lld %lld--\n",f[3][1],R[i-1],R[i]);
			}
			if(i>=3){
				if(R[i]==R[i-2]){
					f[i][2]=0;
				}else if(R[i]==R[i-1]){
					f[i][2]=g[R[i]][0]+1;
				}else{
					f[i][2]=f[R[i]][0];
				}
			}
		}else if(R[i]==i+2){
			f[i][0]=f[R[i]][1];
			if(i>=2){
				if(R[i-1]==R[i])f[i][1]=g[R[i]][1]+2;
				else if(R[i-1]==i+1)f[i][1]=h[R[i]]+1;
				else f[i][1]+=f[R[i]][1];
			}
//			if(i==3){
//				printf("%lld %lld %lld---\n",f[3][1],R[i-1],h[5]);
//			}
			if(i>=3){
				if(R[i]==R[i-2])f[i][2]=0;
				else if(R[i-1]==R[i]&&R[i-2]==i+1){
					f[i][2]+=g[R[i]][1]+1;
				}else if(R[i-1]==R[i]){
					f[i][2]+=g[R[i]][1]+2;	
				}else if(R[i-1]==i+1){
					if(R[i-2]==i+1)f[i][2]+=h[R[i]];
					else f[i][2]+=h[R[i]]+1;
//					if(i==4){
//						printf("%d----\n",f[i][2]);
//					}
				}else f[i][2]+=f[R[i]][1];
//				if(i==5){
//					printf("%lld %lld\n",h[7],f[5][2]);
//				}
			}
		}else{
			f[i][0]=f[R[i]][2];
//			if(i==4)printf("%lld %lld\n",R[i],f[i][0]);
			if(i>=2){
				int r2=R[i],r=max(i,R[i-1]);
				if(r2==r){
					f[i][1]+=(r-i)+g[r2][1];	
				}else if(r+1!=r2){
					f[i][1]+=(r-i)+f[r2][2];
				}else{
					f[i][1]+=(r-i)+h[r2];
				}
			}
			if(i>=3){
				int r3=R[i],r2=max(i,R[i-1]),r=max(i,R[i-2]);
				if(r3==r)f[i][2]=0;
				else if(r3==r2){
					f[i][2]+=g[r3][1]+r2-r;
				}else if(r2+1==r3){
					f[i][2]+=h[r3]+r2-r;
				}else {
					f[i][2]+=f[r3][2]+r2-r;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(R[i]==i)ans+=0;
		else if(R[i]==i+1)ans+=f[R[i]][0];
		else if(R[i]==i+2)ans+=f[R[i]][1];
		else ans=ans+f[R[i]][2];
//		printf("%lld\n",f[3][1]);
//		printf("%lld %lld\n",i,ans);
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		h[i]=0;x[i]=0;R[i]=0;
		f[i][0]=f[i][1]=f[i][2]=0;g[i][0]=g[i][1]=0;
	}
}
bool MT;
signed main(){
//	system("fc /W migrate3.ans migrate.out");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1,c=0;
	cin>>c>>T;
//	cin>>T;
	while(T--)solve();
//	cerr<<((&MS)-(&MT))/(1024.0*1024.0)<<" MB\n"<<clock()/1000.0<<"s Time";
}
/*
0 1
10 6
3 5 7 10 13 17 20 23 24 27 


*/