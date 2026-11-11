
//gaozixiu xianshidiliuzhongxue SN-J00697
#include<bits/stdc++.h>
using namespace std;
string all[20005];
bool vis[20005];
int a[20005];
int ans;
int n,m;
void dfs(int now,int nowans,int have){
	//~ vis[now]=1;
	//~ cout<<a[now]<<" . "<<have<<" " ;
	if(have==m){
		ans=max(ans,nowans);
		//~ cout<<nowans<<"..\n";
		return;
	}
		//~ cout<<nowans<<" "<<a[now]<<" " << (nowans & a[now])<<"\n";

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			cout<<now<<" "<<i<<" "<<(nowans & (a[now]))<<" "<<have+1<<" "<<nowans<<"\n";
			dfs(i,(nowans & (a[now])),have+1);
			vis[i]=0;
		}
	}
}
string erjinzhi(int x){
	string ans;
	while(x){
		ans=ans+char((x%2)+'0');
		x/=2;
	}
	return ans;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	cout<<n-m;
	//~ for(int i=1;i<=n;i++){
		//~ cin>>a[i];
		//~ string[i]=erjinzhi(a[i]);
	//~ }
	//~ for(int i=1;i<=n;i++){
		//~ memset(vis,0,sizeof(vis));
		//~ vis[i]=1;
		//~ dfs(i,a[i],1);
		//~ vis[i]=0;
	//~ }
	//~ cout<<ans;
	//~ cout<<(15 & a[1]);
	return 0;
}
