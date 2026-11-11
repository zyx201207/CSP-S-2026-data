#include<bits/stdc++.h>
using namespace std;
int a[2000005],f[2000005];
int n,d,ans;
void dfs(int s){
	f[s]++;
	for(int i=s+1;i<=n;i++){
		if((a[i]-a[s])<=d){
			dfs(i);
		}
		else{
			return ;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		n=0,d=0,ans=0;
		memset(f,0,sizeof(f));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			dfs(i);
			for(int j=1;j<=n;j++){
				if(f[j]==2){
					ans++;
//					cout<<j<<endl;
				}
			}
			memset(f,0,sizeof(f));
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
