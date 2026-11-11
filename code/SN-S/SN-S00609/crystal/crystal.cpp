#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
int n;
bool f[maxn];
ll m,a[maxn],num=0;
void dfs(int step){
	if(step>m) return;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n&&step<=m;j++){
			if(a[i]!=a[i+1]&&abs(a[i]-a[i+1])<j){
				a[i]++;
				step+=i;
				dfs(step);
			}
			else{
				j++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) f[i]=f[i+1]=1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		if(f[i]==1) num++;
	}
	cout<<num<<'\n';
}
