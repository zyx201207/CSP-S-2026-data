#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf=1e17;

int c,T;
int n;
ll d;
ll g1[305][305];
ll num1[305][305];
ll x[2000005];

inline ll read(){
	char c;
	int f=1;
	ll res=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res*=10;
		res+=(c-'0');
		c=getchar();
	}
	return res*f;
}

inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar((x%10)+'0');
}

void solve1(){
	n=read(),d=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
	  	    g1[i][j]=inf;
	  	    num1[i][j]=0;
		}
	}
	  
	for(int i=1;i<=n;i++){
		g1[i][i]=0;
		num1[i][i]=1;
	    x[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d)
			  break;
			g1[i][j]=g1[j][i]=1;
			num1[i][j]=num1[j][i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<j;k++){
				if(g1[i][k]+g1[k][j]==g1[i][j])
				  num1[i][j]+=(num1[i][k]*num1[k][j]);
				else if(g1[i][k]+g1[k][j]<g1[i][j]){
					g1[i][j]=g1[i][k]+g1[k][j];
					num1[i][j]=num1[i][k]*num1[k][j];
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(num1[i][j]==2){
				ans++;
//	  	        ans+=num1[i][j];
			}
		}
	  	
	}
	  
	write(ans);
	putchar('\n');
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	if(c<=6)
	  while(T--)
	  	solve1();
	return 0;
}