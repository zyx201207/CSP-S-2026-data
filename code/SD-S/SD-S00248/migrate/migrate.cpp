#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,n,e;
ll d,a[N],mi,cnt,ans;
ll dis[20][20];
void dfs(int x,int step){
	if(x==e){
		if(step==mi)cnt++;
		return;
	}
	for(int i=x+1;i<=e;i++){
		if(a[i]-a[x]<=d)dfs(i,step+1);
	}
}
void solveA(){
	ll l=a[2]-a[1];
	if(l==0)printf("0\n");
	else if(d<=l)printf("0\n");
	else{
		ll x=d/l;
		ll ans=n-2*x+1;
		if(ans>0)printf("%lld\n",ans);
		else printf("0\n");
	}
}
void solveB(){
	ll cc=0;
	ll l=a[n]-a[1];
	int s1=0,s2=0;
	if(l<=d)printf("0\n");
	else{
		for(int i=1;i<=n;i++){
			if(a[1]+d>=a[i]&&a[i]+d>=a[n]){
				if(a[1]+d>=a[i-1]&&a[i-1]+d<a[n])s1=i;
				if(a[1]+d<a[i+1]&&a[i+1]+d>=a[n])s2=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i<s1&&i+3>s2)cc++; 
		}
		printf("%lld\n",cc);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
    	ans=0;
    	scanf("%d%lld",&n,&d);
		for(int i=1;i<=15;i++){
    		for(int j=1;j<=15;j++)dis[i][j]=1e18;
		}
    	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(c==11||c==12){solveA();continue;}
        if(c==13||c==14){solveB();continue;}
    	for(int i=1;i<=n;i++){
    		dis[i][i]=0;
    		for(int j=i+1;j<=n;j++){
    			if(a[j]-a[i]<=d){
    				dis[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(dis[i][k]>dis[i][j]+dis[j][k])dis[i][k]=dis[i][j]+dis[j][k];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;mi=dis[i][j];e=j;dfs(i,0);
				if(cnt==2)ans++;
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}

