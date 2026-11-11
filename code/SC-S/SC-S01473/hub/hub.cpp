#include<bits/stdc++.h>
using namespace std;
int n,k,c,T;
int a[5007][5007];
int rand_make(int k){
	int ans=0;
	for(int i=1;i<k;i++){
		ans=max(ans,a[rand()%n+1][rand()%n+1]);
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	srand(c);
	while(T--){
		cin>>n>>k;
		memset(a,0x3f,sizeof(a));
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
			a[y][x]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		int ans=1e9+7;
		for(int i=1;i<10;i++){
			ans=min(rand_make(k),ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}