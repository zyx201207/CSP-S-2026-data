#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,m[10000][10000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(m,0x2f,sizeof(m));
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
			m[a][b]=m[b][a]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					m[i][j]=min(m[i][k]+m[k][j],m[i][j]);
		int maxx=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(m[i][j]<=1000000)
				maxx=max(maxx,m[i][j]);
		cout<<maxx<<endl;
	}
	return 0;
}
