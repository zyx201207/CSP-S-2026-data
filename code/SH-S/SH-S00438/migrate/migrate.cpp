#include<bits/stdc++.h>
using namespace std;
int c,t;
const int maxn=5000;
int n,d,a[maxn],minn[maxn][maxn],ans[maxn][maxn]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n<=300){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int st=i,k=i,cnt=0;
					while(k+d<=j){
						while(abs(a[k]-a[st])<d)
							k++;
						k--;
						cnt++;
						st=k;
					}
					cnt++;
					if(cnt<minn[i][j]){
						ans[i][j]=1;
						minn[i][j]=cnt;
					}
					if(cnt==minn[i][j])
						ans[i][j]++;
				}
			}
			int x=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(ans[i][j]==2)
						x++;
			cout<<x;
		}
		else
			cout<<0;
	}
	return 0;
}
