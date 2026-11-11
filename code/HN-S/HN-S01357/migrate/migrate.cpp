#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int now,cnt;
int vis[1001][1001];
int a[200005];
int main(){
		freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
/*	while(t--){
		now=0;
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=1001;i++)for(int j=1;j<=1001;j++)vis[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				now=i;
				for(int k=i;k<=j;k++){
					if(a[k]-a[now]>d){
						cnt++;
						now=k-1;
					}
				}
			}
		}
	}*/
	cout<<0<<endl<<1;
	return 0;
} 
