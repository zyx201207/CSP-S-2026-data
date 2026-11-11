#include<bits/stdc++.h>
using namespace std;
int N[5000000];
int n,m;
int ans=0;
void dfs(int step,int v,int last){
	//cout<<v<<" ";
	if(step==m){
		//cout<<v<<" ";
		ans=max(ans,v);
		return ;
	}
	for(int i=last+1;i<=n;i++){
		dfs(step+1,N[i]&v,i);
	}
}
int main(){
	int maxn=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>N[i];
		if(N[i]>maxn) maxn=N[i];
	}
	if(m==1) cout<<maxn;
	else if(m==n){
		int f=int(pow(2,30)-1);
		for(int i=1;i<=n;i++){
			f=f&N[i];
		}
	}
	else dfs(0,int(pow(2,30)-1),0);
	cout<<ans;
	return 0;
}
