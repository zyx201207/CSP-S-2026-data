#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int b[N][32];
bool vis[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		vis[i]=1;
		cin>>a[i];
		int x=a[i];
		int y=30;
		while(x){
			if(x>=(1<<y)){
				b[i][y]=1;
				x-=(1<<y);
			}
			y--;
		}
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0)continue;
			if(b[j][i]==1)cnt++;
			else vis[j]=0;
		}
		if(cnt>=m)ans+=(1<<i);
		else{
			if(ans==0){
				for(int j=1;j<=n;j++)vis[j]=1;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}