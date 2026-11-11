#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],vis[200005],ans=-1,ans2=-1;
struct node{
	int data,cnt;
}b[200005];
int randint(int x,int y){
	int t=(rand()<<16)+rand();
	int tt=(t%(y-x+1))+x;
	return tt;
}
void dfs(int x,int cnt,int sum){
	if(x==0){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(i,1,a[i]);
			vis[i]=0;
		}
	}
	if(cnt==m){
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(i,cnt+1,sum&a[i]);
		vis[i]=0;
	}
}
bool cmp1(int x,int y){
	return x>y;
}
bool cmp2(node x,node y){
	return x.data>y.data;
}
bool timeup(){
	double shi=clock();
	if(shi>900.0)return true;
	return false;
}
void tanxin(){
	for(int i=1;i<=10000;i++){
		if(timeup()){
			cout<<ans2;
			return;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			b[i].data=a[i]+randint(-100,100);
			b[i].cnt=i;
		}
		sort(b+1,b+n+1,cmp2);
		int sum=a[b[1].cnt];
		for(int i=2;i<=m;i++){
			sum&=a[b[i].cnt];
		}
		ans2=max(ans2,sum);
	}
	cout<<ans2;
}
signed main(){
	srand(time(NULL));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,-1);
		cout<<ans<<" ";
		//dfs 
	}else{
		tanxin();
	}
	//老爷随机化贪心
	return 0;
}
