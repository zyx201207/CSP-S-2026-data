#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],maxn=0,v[100005];
void dfs(int deep,int s,int start){
	if(deep==m+1&&s>maxn&&deep>2){
		maxn=s;
		return ;
	}
	
	for(int i=start;i<=n;i++){
		
		if(deep==1){
			dfs(deep+1,a[i],i+1);
			continue;
		}
		dfs(deep+1,s&a[i],i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	dfs(1,0,1);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	cout<<maxn;
	return 0;
}
