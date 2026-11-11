#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define N 2000010
#define inf 2000010
using namespace std;
ll read(){
	int f=0;
	ll ans=0;
	char c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10ll+c-'0';
		c=getchar();
	}
	if(f){
		ans*=-1;
	}
	return ans;
}
int c,t,n;
ll d,ans,x[N],dp[N],minn[N],num[N];
void solve(){
	n=read();d=read();
	ans=0;
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	if(n>6000){
		if(x[1]+d<x[3]){
			printf("0\n");
		}else{
			printf("%d\n",n-3);
		}
		return;
	}
	for(int k=1;k<=n;k++){
		minn[k]=0;
		for(int i=k+1;i<=n;i++){
			dp[i]=0;
			minn[i]=inf;
			num[i]=0;
			ll f=x[i]-d;
			int pos=lower_bound(x+1,x+n+1,f)-x;
		//	printf("%d %d-------",pos,i);
			for(int j=max(pos,k);j<i;j++){
				if(minn[j]+1<minn[i]){
					minn[i]=minn[j]+1;
					if(num[j]==0){
						num[i]=1;
					}else{
						num[i]=num[j];
					}
				}else if(minn[j]+1==minn[i]){
					num[i]+=num[j];
				}
			}
		//	printf("%lld %lld\n",num[i],minn[i]);
			if(num[i]==2){
				ans++;
			}
		}
	//	printf("*******************\n");
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		solve();
	}
	return 0;
}