#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn];
int n,m;
long long cnt=0;
void dfs(int dpt,long long num,int ge){
	if(ge==m){
		cnt=max(num,cnt);
		//cout<<num<<'\n';
		return ;
	}
	if(dpt==n){
		return ;
	}
	int c=num&a[dpt+1];
	dfs(dpt+1,c,ge+1);
	dfs(dpt+1,num,ge);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long ababab=a[1];
		for(int i=2;i<=n;i++){
			ababab&=a[i];
		}
		cout<<ababab;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<cnt;
	return 0;
}
