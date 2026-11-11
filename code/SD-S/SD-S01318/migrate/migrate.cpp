#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int n,d;
long long minn=0x3f3f3f3f;
void dfs(int x,int y,int ss){
	if(x==y){
		if(ss<minn) minn=ss;
		return;
	} 
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs(i,y,ss+1);
		}
		else{
			break;
		}
	}
}
int s;
void dfs2(int x,int y,int ss){
	if(ss==minn&&x==y){
		s++;
		return;
	} 
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			dfs2(i,y,ss+1);
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=0,minn=10000000;
				dfs(i,j,0);
				dfs2(i,j,0);
				if(s==2){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
