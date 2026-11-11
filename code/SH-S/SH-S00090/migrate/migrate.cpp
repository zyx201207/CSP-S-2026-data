#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+6;
int n;
int c,t;
long long d;
long long x[MAXN];
vector<int>edge[MAXN];
int f[5005][5005];
bool b[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c!=13&&c!=14&&c!=11&&c!=12){
		while(t--){
			cin>>n>>d;
			int g=1;
			bool flag=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				while(x[i]-x[g]>d)g++;
				if(g!=i&&x[i]-x[g]<=d){
					edge[i].push_back(g);
					edge[g].push_back(i);
					f[i][g]=1;
					f[g][i]=1;
					flag=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					if(!f[i][j]){
						int num2,num3;
						for(int k=i+1;k<j;k++){
							if(f[i][k]+f[k][j]==2){
								f[i][j]=2;
								num2++;
							}else if(f[i][k]+f[k][j]==3){
								num3++;
							}
						}
						if(num2==2){
							ans++;
						}else if(num2==0&&num3==2){
							ans++;
						}
					}
				}
			}
			if(!flag){
				cout<<0;
				continue;
			}
			cout<<ans<<endl; 
			for(int i=1;i<=n;i++){
				edge[i].clear();
				for(int j=1;j<=n;j++){
					f[i][j]=0;
					b[i][j]=0;
				}
			}
			
		}
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			int g=1;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				while(x[i]-x[g]>d)g++;
				if(g!=i&&x[i]-x[g]<=d){
					edge[i].push_back(g);
					edge[g].push_back(i);
				}
			}
			int sp;
			for(int i=1;i<=n;i++){
				if(edge[i].size()==n-1){
					sp=i;
				}
			}
			for(int i=1;i<=n;i++){
				edge[i].clear();
			}
		}
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int g=1;
			bool flag=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				while(x[i]-x[g]>d)g++;
				if(g!=i&&x[i]-x[g]<=d){
					edge[i].push_back(g);
					edge[g].push_back(i);
					flag=1;
				}
			}
			if(!flag){
				cout<<0;
				continue;
			}
			for(int i=1;i<=n;i++){
				edge[i].clear();
			}
			
		}
	}
	return 0;
} 
