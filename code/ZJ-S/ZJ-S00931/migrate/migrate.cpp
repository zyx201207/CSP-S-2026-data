#include<bits/stdc++.h>
using namespace std;
int op,t,n,d,x[60000],ans,num,dist[6000][6000];
bool A;
inline int read(){
	long long f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
bool dfs(int x1,int cnt,int xc,int y){
	if(x1==y&&cnt==dist[xc][y]){
		num++;
	}
	for(int i=x1+1;i<=n;i++){
		if(x[i]-x[x1]<=d){
			dfs(i,cnt+1,xc,y);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	op=read(),t=read();
	if(op==11||op==12) A=true;
	while(t--){
		n=read(),d=read();
		memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dist[i][i]=0;
			if(i>1) dist[i-1][i]=x[i]-x[i-1];
		}
		if(A){
			d=d/(a[2]-a[1]);
			if(d<=1) cout<<0;
			else cout<<n-d-1;
			continue;
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				for(int k=i;k<=j;k++){
					for(int l=k+2;l<=j;l++){
						if(x[l]-x[k]<=d){
							dist[i][j]=min(dist[i][j],dist[i][k]+dist[l][j]+1);
						}
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				num=0;
				dfs(i,0,i,j);
				if(num==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
