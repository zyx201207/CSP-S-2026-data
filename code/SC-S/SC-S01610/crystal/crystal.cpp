#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll d[N];
int ma=0;
inline void dfs(int i,ll used,int s,int j){
	if(used>m||i>n||j+m-i<=s)
		return;
	ma=max(ma,s);
	int uu=s*(d[i+1]-d[j]);
	dfs(i+1,used+uu,s+1,i+1);
	dfs(i+1,used,s,j);
}	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(unsigned int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(unsigned int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i]-a[i-1];
	}
	dfs(0,0,0,0);
	cout<<ma;
	return 0;
}//qwq