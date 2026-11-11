#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[210000],bi[210000];
bool vis[210000];
int n,m,ans=0;
void dfs(int deep,int c){
	if(deep==m+1){
		ans=max(ans,c);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(deep!=1) dfs(deep+1,c&a[i]);
			else dfs(deep+1,a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int g=1,fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i]+1;
		if(g!=0) while(x%2==0&&x>0) x/=2,bi[i]++;
		if(a[i]==1+a[i-1]&&i>1) fl++;
		if(x==1) g++;
		else g=0;
	}
	if(fl==n){
		int an=a[n];   
		for(int i=n-1;i>=n-m+1;i--){
			an=an&a[i];
		}                           
		cout<<an<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	// CCF zui shan de yi ji O(nm) you 50pts
	//cheng gong zuo chu te shu B
	// yu ji 60+
	return 0;
}                        