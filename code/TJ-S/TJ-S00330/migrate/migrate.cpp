#include<bits/stdc++.h>
using namespace std;
long long t,n,d,a[2000010],cnt,ans,c,d1,lg;
void fd(int x,int y){
	if(x==y){
		return;
	}
	lg++;
	for(int i=y;i>=x+1;i--){
		if(a[i]-a[x]<=d1){
			fd(i,y);
			return;
		}
	} 
	return;
}
void dfs(int x,int y,int og){
	if(x==y&&og==lg){
		cnt++;
		return;
	}
	if(x==y){
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d1){
			dfs(i,y,og+1);
		}
	}
	return; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		ans=0;
		cin>>n>>d1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				lg=0;
				fd(i,j);
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
