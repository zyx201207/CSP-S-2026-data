#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXM=500005;
const int MAXQ=25;
const long long INF=10000000005;
long long v[MAXN];
long long amap[MAXN][MAXN];
long long tmap[MAXM][MAXQ];//tmap[i][j]:The jth line value(TIME) of ith Station
long long nmap[MAXM][MAXQ];//nmap[i][j]:The jth line NUMBER of ith Station
long long c,n,m,d,q;
long long ans[MAXN];
int vis[MAXN];


bool debugmode=false;
void tmp1(){
	if(debugmode == false)return;
	for(int i=1;i<=m;i++){
		cout<<i<<",";
		for(int j=0;j<=n;j++){
			cout<<nmap[i][j]<<",";
		}
		for(int j=1;j<=n;j++){
			cout<<tmap[i][j]<<",";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<tmap[i][j]<<",";
		}
		cout<<endl;
	}
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			cout<<amap[i][j]<<",";
		}
		cout<<endl;
	}
}
void tmp2(){
	if(debugmode == false)return;

	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			cout<<amap[i][j]<<",";
		}
		cout<<endl;
	}
}
void tmp3(){
	if(debugmode == false)return;
	cout<<endl;
	for(int i=0;i<=n+1;i++){
		cout<<ans[i]<<",";
		
	}
	cout<<endl;
}


void check(long long s,long long e){
	vis[0]=1;
	for(long long i=1;i<=n+1;i++){//O(n)
		ans[i]=INF;
		vis[i]=0;
		amap[0][i]=amap[i][0]=amap[n+1][i]=amap[i][n+1]=INF;
	}
	for(long long i=1;i<=nmap[s][0];i++){//O(d)
		amap[0][nmap[s][i]]=tmap[s][i];
		ans[nmap[s][i]]=tmap[s][i];
		//cout<<nmap[s][i]<<":"<<ans[nmap[s][i]]<<"\n";
	}
	for(long long i=1;i<=nmap[e][0];i++){//O(d)
		amap[nmap[e][i]][n+1]=tmap[e][i];
	}
	tmp2();
	if(debugmode == true)cout<<endl;//
	for(long long i=1;i<=n+1;i++){//O(n^2)
		//cout<<"YES!\n";
		long long minn=0,mina=10000000005;
		for(long long j=1;j<=n;j++){//Minnest Value
			//cout<<ans[j]<<" ";
			if(vis[j]==0 && ans[j]<mina){
				minn=j;
				mina=ans[i];
				//cout<<"RIGHT!";
				
			}
		}
		
		if(debugmode == true)cout<<endl<<minn<<",";//
		vis[minn]=1;
		for(long long j=1;j<=n+1;j++){
			ans[j]=min(ans[j],ans[minn]+amap[minn][j]);
		}
	}
	tmp3();
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long u,v;
			scanf("%lld %lld",&u,&v);
			nmap[u][++nmap[u][0]]=i;
			tmap[u][nmap[u][0]]=v;
		}
	}//Save the EDGE(uncompleted)
	for(long long i=1;i<=n;i++){//O(n^2)
		for(long long j=1;j<=n;j++){
			if(i==j)amap[i][j]=0;
			else amap[i][j]=INF;
		}
	}//Memset(Init)
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<nmap[i][0];j++){
			for(long long k=j+1;k<=nmap[i][0];k++){
				if(amap[nmap[i][j]][nmap[i][k]]>(tmap[i][j]+tmap[i][k])){
					amap[nmap[i][k]][nmap[i][j]]=amap[nmap[i][j]][nmap[i][k]]=(tmap[i][j]+tmap[i][k]);
				}
			}
		}
	}//YuChuLi
	//tmp1();
	for(long long i=1;i<=q;i++){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		check(x,y);
		printf("%lld \n",ans[n+1]+v[x]+v[y]);
	}
	
	return 0;
}