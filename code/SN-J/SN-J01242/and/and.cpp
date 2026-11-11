#include<bits/stdc++.h>
using namespace std;

const int N=2e5+9;
int a[N];
//bool vis[N];
int n,m;
long long ans=-1;

void dfs(int st,int c,long long mx){
	if(c<=0||st==n){
		ans=max(ans,mx);
		return;
	}else{
		for(int i=st;i<=n;i++){
//			vis[i]=true;
			if(c<=0){
				ans=max(ans,mx);
				return ;
			}
			
			dfs(st+1,c-1,a[i]&mx);
			
//			vis[i]=false;
		}
	}
} 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(n>2000){
		for(int i=1;i<=m;i++){
			ans&=a[i]; 
		}	
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,m,-1);
	cout<<ans<<endl;
	return 0;
} 

