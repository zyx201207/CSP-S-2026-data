#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int c,t;
int n,d;
int a[2000001];
int u=2147483647;
int cnt=0;
void dfs(int x,int e,int dd){
	if(x==e){
		if(dd<u){
			u=dd;
			cnt=1;
		}else if(dd==u){
			cnt++;
		}
		return;
	}
	for(int i=x+1;i<=e;i++){
		int k=abs(a[x]-a[i]);
		if(k>d) break;
		dfs(i,e,dd+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n>=9){
			//TODO
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				u=2147483647;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
