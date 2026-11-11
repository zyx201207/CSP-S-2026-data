#include<bits/stdc++.h>
using namespace std;
const int N=10010;
long long n,T,c,d;
long long dis[N][N],f[N],aq[N],ans,cnt[N][N],lst;
bool flag;
long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	while(T--){
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=1e18;
				cnt[i][j]=0;
			}
		}
		ans=0;
		flag=false;
		for(int i=1;i<=n;i++){
			aq[i]=read();
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(int j=i+1;j<=n;j++){
				if(aq[j]-aq[i]<=d){
					dis[i][j]=1;
				}else{
					continue;
				}
			}
		}
		for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=i+1;k<j;k++){
						if(dis[i][k]==1e18||dis[k][j]==1e18)continue;
						if(dis[i][j]>=dis[i][k]+dis[k][j]){
							if(dis[i][j]==dis[i][k]+dis[k][j]){
								cnt[i][j]++;
							}else{
								dis[i][j]=dis[i][k]+dis[k][j];
								cnt[i][j]=1;
							}
						}
					}
				}
			}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2&&dis[i][j]!=1e18){
					//write(i);
					//write(j);
					ans++;
				}
			}
		}
		write(ans);
	}

    return 0;
}
