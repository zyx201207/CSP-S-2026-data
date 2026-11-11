#include<bits/stdc++.h>
using namespace std;

vector<int>mp[50005];
struct node{
	int x,y;
};

int c,n,m,d,q,w[500010],t[505][500010],s[505][505];
//int w[1005][1005];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	
	cin >>c>>n>>m>>d>>q;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=1e9;
		}
		for(int j=1;j<=m;j++){
			t[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin >>a >>b;
			t[i][a]=b;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<mp[i].size();i++){
			for(int k=0;k<mp[i].size();i++){
				s[mp[j][j]][mp[i][k]]=s[mp[i][k]][mp[i][j]]=min(s[mp[i][k]][mp[i][j]],t[mp[i][k]][i]+t[mp[i][j]][i]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=1e9;cin >>x>>y;
		for(int j=0;j<mp[x].size();j++){
			for(int u=0;u<mp[y].size();u++){
				ans=min(ans,s[mp[x][j]][mp[y][u]]+w[x]+w[y]);
			}
		}
			cout <<ans<<endl;
	}

	return 0;
	}