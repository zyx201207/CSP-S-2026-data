#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[20005],len[5005][5005],cnt[5005][5005],ans;
long long read(){
	char s=getchar();
	long long f=1,x=0;
	if(s=='-'){
		f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}
long long dfs(long long s,long long t){
	long long k=s+1;
	while(k<=t&&(x[k]-x[s])<=d){
		len[s][k]=1;
		k++;
	}
	k--;
	if(k<t){
		len[s][t]=len[s][k]+dfs(k,t);
		return len[s][t];
	}else{
		return 1;
	}
}
void dfs2(int s,int s1,int t,int l){
	if(s==t){
		if(l>len[s1][t]){
			return ;
		}else{
			cnt[s1][t]++;
			return ;
		}
	}
	for(int i=s+1;i<=t;t++){
		if(x[i]-x[s]>d){
			break;
		}
		dfs2(i,s1,t,l+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				cnt[i][j]=0;
				len[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			x[i]=read();
			len[i-1][i]=1;
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(len[i][j]){
					continue;
				}
				len[i][j]=dfs(i,j);
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				dfs2(i,i,j,0);
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
}