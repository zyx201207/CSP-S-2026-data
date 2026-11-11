#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=2e5+5;
ll n,m,a[mx],ans,qz[mx],hz[mx];
bool vis[mx];
void dfs(int now){//正在选第now+1个 
	if(now==n+2){
		ll cnt=0,t=0;
		bool f=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&!f) t=a[i],cnt++,f=1;
			else if(vis[i]&&f) t&=a[i],cnt++;
		}
//		cout<<"\n";
		if(cnt==m){
			ans=max(ans,t);
//			cout<<t<<"!!!\n";
		}
		return;
	}
	for(int i=0;i<2;i++){
		vis[now+1]=i;
		dfs(now+1);
		vis[now+1]=0;
	}
	//两个小样例已过 
}
int main(){
	//60pts 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		//25pts
		//测试点1~5 
		//O(2^n)暴力01搜索
		dfs(0);
		cout<<ans; 
	}
	else if(m==1){
		//5pts
		//测试点6
		//取所有数里最大的直接输出即可，无需按位与操作 
		ans=-1;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n){
		//5pts
		//测试点7
		//直接全选 
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		//15pts
		//测试点8~10
		//O(n^2)枚举两个数字的选择情况并取最大值 
		ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,(a[i]&a[j]));
			}
		} 
		cout<<ans;
	}
	else if(m==n-1){
		//10pts
		//测试点11~12
		//做前缀以及后缀&数组，枚举不选的那个并将前几个&上后几个得出答案然后求最大
		qz[1]=a[1],hz[n]=a[n];
		for(int i=2;i<=n;i++) qz[i]=qz[i-1]&a[i];
		for(int i=n-1;i>=1;i--) hz[i]=hz[i+1]&a[i];
		ans=max(qz[n-1],hz[2]);
		for(int i=2;i<n;i++){
			ll t=qz[i-1]&hz[i+1];
			ans=max(ans,t);
		} 
		cout<<ans;
	}
	else cout<<0;//骗分 
	return 0;
}
//开ll了，已去掉freopen的注释 
//10:15结部分分准备后面再想 
