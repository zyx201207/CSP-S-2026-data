#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,b[200005];
void dfs(int x,int gs,int add){
	if(gs==m){
		ans=max(add,ans);
	}
	if(gs<m)
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				if(gs==0){
				b[i]=1;
				dfs(i,gs+1,add+a[i]);
				b[i]=0;
			}
			else{
				b[i]=1;
				dfs(i,gs+1,add & a[i]);
				b[i]=0;
			}	
			}
		
		}
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
dfs(1,0,0);
cout<<ans;
}
