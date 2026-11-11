#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int x[N],dis[N][N];
inline int read(){
	char x=getchar();
	int f=1,ans=0;
	while(x<'0'||x>'9'){
		if(x=='-')
			f=-1;
		x=getchar();
	}
	while(x<='9'&&x>='0'){
		ans=ans*10+x-'0';
		x=getchar();
	}
	return ans*f;
}
int check(int x,int u,int v,int num){
	if(x==v&&num==dis[u][v])
		return 1;
	if(num==dis[u][v])
		return 0;
	int sum=0;
	for(int i=x+1;i<=v;i++){
		if(dis[x][i]==1)
			sum+=check(i,u,v,num+1);
		else
			break;
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=1e9;
		for(int i=1;i<=n;i++)
			x[i]=read();
		for(int i=n;i>0;i--)
			x[i]-=x[i-1];
		x[1]=0;
		for(int i=1;i<=n;i++){
			int cnt=0,ans=1;
			for(int j=i+1;j<=n;j++){
				cnt+=x[j];
				if(cnt>d)
					cnt=x[j],ans++;
				if(x[j]>d)
					break;
				dis[i][j]=dis[j][i]=ans;
			}
		}
		int sum=0;
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(check(u,u,v,0)==2)
					sum++;
		cout<<sum<<"\n";
	}
	return 0;
}
