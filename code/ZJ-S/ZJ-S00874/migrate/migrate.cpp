#include <bits/stdc++.h>
using namespace std;
int anss,ans=INT_MAX,s,c,t,a[200100],n,d;
int dfs(int v,int x,int y){
	if(x==v){
		if(y<ans){
			ans=y;
			s=1;
		}
		else if(y==ans){
			s++;
		}
		//cout<<y<<" ";
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(v,i,y+1);
		}
		else{
			break;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		anss=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=INT_MAX;
				s=0;
			    dfs(j,i,0);
			    if(s==2){
			    	anss++;
				}
				//cout<<"fsfsd"<<ans<<" ";
			}
		}
		cout<<anss<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/