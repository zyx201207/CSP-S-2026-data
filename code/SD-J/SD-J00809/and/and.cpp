#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int a[200005],maxn=-1;
bool vis[200005];
void dfs(int num,int ans){
	if(num>=m){
		maxn=max(maxn,ans);
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				if(num==0) dfs(num+1,a[i]);
				else dfs(num+1,ans&a[i]);
				vis[i]=0;
			}
			else continue;
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0);
		cout<<maxn;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=a[i]&maxn;
		}
		cout<<maxn;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else{
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	//else cout<<'3';
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
fc and1.ans and1.out /n
fc and2.ans and2.out /n
fc and3.ans and3.out /n
fc and4.ans and4.out /n
fc and5.ans and5.out /n
finished.
*/
