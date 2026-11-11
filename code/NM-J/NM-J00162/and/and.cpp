#include<bits/stdc++.h>
using namespace std;
const int NN=2*1e5+10;
int n,m;
long long a[NN];
long long ans;
void dfs(int num,long long mx,int sum){
	if(num==n&&sum!=m){
		return ;
	}
	if(sum==m){
		ans=max(ans,mx);
		return ;
	}
	dfs(num+1,mx,sum);
	dfs(num+1,(mx&a[num+1]),sum+1);
	return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	dfs(0,2147483647,0);
	cout<<ans;
    return 0;
}

