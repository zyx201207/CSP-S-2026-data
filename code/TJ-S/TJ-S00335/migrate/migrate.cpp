#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long n,d;
long long x[N];
long long mind=0x3f3f3f;
long long flag1=1,d1=1;
long long tt[N],minn=2*N;
void dfs(int u,int v,long long step){
	//cout<<u<<' '<<v<<' '<<step<<' ';
	if(u==v){
		minn=min(minn,step);
		tt[step]++;
		//cout<<minn<<' '<<tt[step]<<endl;
		return;
	}
	for(int j=u+1;j<=v;j++){
		//cout<<x[j]<<' '<<x[u]<<' '<<x[j]-x[u]<<endl;
		//if(x[j]-x[u]<=d) 
		dfs(j,v,step+1);
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			mind=min(mind,x[i]-x[i-1]);
			if(i>=2){
				d1=x[2]-x[1];
				if(x[i]-x[i-1]!=d1) flag1=0;
			}	
		}
		if(d<=mind){
			printf("0\n");
			continue;
		}
		if(flag1==1){
			if(d/d1<=1 || d/d1>2) printf("0\n");
			else{
				long long mink=d/d1+1,maxk=2*(d/d1)-1;
				long long ans=0;
				for(int i=1;i<=n;i++){
					if(i+mink>n) break;
					long long minj=i+mink,maxj=min(i+maxk,n);
					//printf("(%d,%lld,%lld)",i,minj,maxj);
					ans+=maxj-minj+1;
				}
				printf("%lld\n",ans);
			}
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//printf("(%d,%d)",i,j);
				memset(tt,0,sizeof(tt));
				minn=2*N;
				dfs(i,j,0);
				if(tt[minn]==2){
					ans++;
					//cout<<"!!!";
				}
				//cout<<"\n";
			}
		}
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
/*
0 3
4 4
2 4 6 8
5 2
2 4 6 8 10
7 7
2 4 6 8 10 12 14

1
2
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
