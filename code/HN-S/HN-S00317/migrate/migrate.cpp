#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
const int N=2e6+100;
int a[N],b[N],dis[N],dis1[N];
void dfs(){
	int i=2,j=1;
	while(i<=n){
		if(b[i]-b[j]<=d){
			if(dis[i]>dis[j]+1){
				dis[i]=dis[j]+1;
			}
			i++;
		}else j++;
	}
}
void dfs1(){
	int i=n-1,j=n;
	while(i>=0){
		if(b[j]-b[i]<=d){
			if(dis1[i]>dis1[j]+1){
				dis1[i]=dis1[j]+1; 
			}
			i--;
		}else j--;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		a[0]=a[1];
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+a[i]-a[i-1];
		}
		memset(dis,127,sizeof(dis));
		dis[1]=0;
		dis1[n]=0;
		dfs();
		dfs1();
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(dis[i]!=dis1[i]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
