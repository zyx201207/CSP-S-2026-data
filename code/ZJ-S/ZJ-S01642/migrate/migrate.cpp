#include<bits/stdc++.h>
using namespace std;
int aaaaa;
int t,n;
long long d;
long long a[2000005];
long long read(){
	char c=getchar();
	long long res=0;
	short f=1;
	while(c<'0' || c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
void write(long long x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int f[305][305][305];
vector<int> v[2000005];
int ans;
void solve_123456(){
	t=read();
	while(t--){
		memset(f,0,sizeof f);
		n=read(),d=read();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					//cout<<a[j]<<" "<<a[i]<<endl;
					f[i][j][1]=1;
					v[i].push_back(j);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int l=0;l<v[j].size();l++){
						//cout<<k<<" "<<i<<" "<<j<<" "<<l<<endl;
						f[i][v[j][l]][k+1]+=f[i][j][k];
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(f[i][j][k]!=0){
						//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
						if(f[i][j][k]==2)ans++;
						break;
					}
				}
			}
		}
		write(ans);
		putchar('\n');
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	aaaaa=read();
	if(aaaaa<=6){
		solve_123456();
	}
	return 0;
}
