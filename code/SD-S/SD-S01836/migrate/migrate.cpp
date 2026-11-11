#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,d;
int a[5005][5005];
int b[5005][5005];
int c[5005],e[5005][5005],f[5005],g[5005],ee[5005][5005];//g统计在第i坐标最多能跳几格 ,b统计的是1步可以跳到哪些地方 
int kkk=0;
void dfs(int x,int j,int hh){
	//kkk++;
	if(j==a[hh][x]){
		e[hh][x]++;
	}
	else if(j<a[hh][x]){
		a[hh][x]=j;
		e[hh][x]=1;
	}
	else{
		return;
	}
	if(x==n){
		return;
	}
	for(int hhh=g[x];hhh>=1;hhh--){
		dfs(b[x][hhh],j+1,hh);
	} 
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cxx,t;
	cin>>cxx>>t;
	if(cxx<=10){
		while(t--){			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j]=b[i][j]=e[i][j]=0;
				}
				c[i]=g[i]=0;
			}
			for(int i=1;i<=n;i++){
				cin>>c[i];
			}
			for(int i=1;i<=n;i++){
				int cc=i,hh=1;
				for(int j=i+1;j<=n;j++){
					if(c[j]-c[j-1]>d){
						break;
					}
					else{
						if(c[j]-c[cc]>d){
							hh++;
							cc=j-1;
							j--;
							continue;
						}
						else{
							a[i][j]=hh;
							if(hh==1){
								b[i][++g[i]]=j;
							} 
						}
					}
				}
			}
			//cout<<1<<endl;
			for(int i=1;i<=n-1;i++){
				dfs(i,0,i);
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(e[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		//cout<<kkk;
	}
	return 0;
}

