#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,subs[505][505],w[500005],t1,t2,t3,t4;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(subs,0x3f3f3f3f3f3f3f3f,sizeof(subs));
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld%lld",&c,&t1,&t2,&t3,&t4);
		subs[t1][t3]=t4+t2,subs[t3][t1]=t2+t4;
	}
	for(int i =1;i<=m;i++)subs[i][i]=0;
	for(int k = 1;k<=m;k++)
		for(int i= 1;i<=m;i++)
			for(int j = 1;j<=m;j++)
				subs[i][j]=min(subs[i][j],subs[i][k]+subs[k][j]);
    //for(int i= 1;i<=n;i++)for(int j = 1;j<=n;j++)cout <<subs[i][j]<<" \n"[j==n];
    while(q--){
		scanf("%lld%lld",&t1,&t2);
	//	if(4000000000000000000<subs[t2][t1]+w[t1]+w[t2]){
	//		cout <<"------------"<<t1<<" "<<t2<<" "<<subs[t2][t1]<<w[t1]<<w[t2];
	//		return 0;
	//	}
	//    cout <<t1<<" "<<t2<<" "<<subs[t1][t2]<<" "<<w[t1]<<" "<<w[t2]<<" ";
		printf("%lld\n",subs[t1][t2]+w[t1]+w[t2]);
	}
	
}

