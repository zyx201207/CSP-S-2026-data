#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N];
bool b[N];
int n,m;
int maxx=0;
void dfs(int now,int ans,int j){
	if(now==m){
		maxx=max(maxx,ans);
		return;
	}
	for(int i=j;i<=n;i++){
		if(b[i]==false){
			b[i]=true;
			dfs(now+1,ans&a[i],i+1);
			b[i]=false;
			dfs(now,ans,j+1); 
		}
		return;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	int ans=a[1],cnt=a[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		ans=ans&a[i];
		cnt=max(cnt,a[i]);
	}
	if(m==1) cout<<cnt;
	else if(m==n) cout<<ans;
	else if(m==2){
		cnt=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i]&a[j];
				cnt=max(cnt,t);
			}
		} 
		cout<<cnt;
	}
	else{
		for(int i=1;i<=n-m+1;i++){
			dfs(0,a[i],i);
		}
		cout<<maxx;
	}
	return 0;
}
