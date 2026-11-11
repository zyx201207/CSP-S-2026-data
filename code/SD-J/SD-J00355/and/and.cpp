#include<iostream>
using namespace std;
int n,a[200005],m,ans;
long long num;
void dfs(int step,int num,int l){
	if(step==m+1){
		ans=max(ans,num);
		return;
	}
	if(step+n-l+1<m)return;
	for(int i=l;i<=n&&step+n-i>=m;i++){
		if(num!=-1)dfs(step+1,num&a[i],i+1);
		else dfs(step+1,a[i],i+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,-1,1);
	cout<<ans;
	return 0;
}
