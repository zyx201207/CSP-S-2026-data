#include<bits/stdc++.h>
#define int long long
#define MAX 1152921504606846976
using namespace std;
int c,t,s;
int n,d,ans;
int a[2000001];
int p[5001][5001];
int dis[5001][5001];
bool v[2000001];
void dfs(int began,int end,int now,int len){
	cout<<now<<' ';
	if(len>dis[began][end])return;
	if(now==end){
		if(len==dis[began][end])s++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]&&p[now][i]!=MAX){
			v[i]=1;
			dfs(began,end,i,len+p[now][i]);
			v[i]=0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				p[i][j]=p[j][i]=MAX;
				if(abs(a[i]-a[j])<=d)p[i][j]=p[j][i]=abs(a[i]-a[j]);
				dis[i][j]=dis[j][i]=p[i][j];
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<i<<'/'<<j<<':';
				s=0;
				v[i]=1;
				dfs(i,j,i,0);
				v[i]=0;
				//cout<<s<<"//";
				if(s==2){
					cout<<"RA:"<<i<<' '<<j<<'\n';
					ans++;
				}
				//cout<<dis[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/
