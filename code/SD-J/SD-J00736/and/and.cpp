#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int a[N];
int an=2147483647;
int maxn;
bool b[N]={0};
void dfs(int x,int index){
	if(x>m){
		maxn=max(an,maxn);
		return ;
	}
	b[index]=true;
	for(int i=x+1;i<=n;i++){
		if(!b[i]){
			an&=a[i];
			b[i]=true;
			dfs(x+1,i);
			b[i]=false;
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
	dfs(0,0);
	cout<<maxn<<endl;
}
