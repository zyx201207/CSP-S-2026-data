#include <bits/stdc++.h>
using namespace std;
const int N=50050;
int c,t;
long long n,d,x[N],f[N],g[N][N],ans;
bool b1=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])b1=false;
		}
		if(b1){
			long long dd=x[2]-x[1];
			long long k=d/dd;
			cout<<(n-1)/k+1<<endl;
		}
		else{
			int j=0;
			long long sum=0;
			for(int i=1;i<=n-1;i++){
				while(j<=n){
					if(sum+x[j]-x[j-1]>d)break;
					sum=sum+x[j]-x[j-1];
					j++;
				}
				f[i]=j-1;
				sum=sum-(x[i+1]-x[i]);
			}
			//×î¶Ì¾àÀë 
			long long cnt=0;
			for(int i=1;i<=n-1;i++){
				for(int j=f[i]+1;j<=n;j++){
					int p=f[i];
					cnt=1;
					while(p<=j){
						if(f[p]>j)break;
						p=f[p];
						cnt++;
					}
					if(p<j)cnt++;
					g[i][j]=cnt;
				}
			}

			long long num=0;
			for(int i=1;i<=n-1;i++){
				for(int j=f[i]+1;j<=n;j++){
					for(int k=f[i]+1;k<j;k++){
						num=0;
						if(g[i][k]+g[k][j]==g[i][j])num++;
					}
					if(num==1)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
