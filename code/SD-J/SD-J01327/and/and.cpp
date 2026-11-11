#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
vector<int>v1,v2;
void dfs(int w,int res){
	if(!w){
		printf("%d",res);
		return;
	}
	v2.clear();
	for(auto i:v1){
		if(i&(1<<(w-1))) v2.push_back(i);
	}
	if(v2.size()>=m){
		v1.clear();
		for(auto i:v2) v1.push_back(i);
		dfs(w-1,res+(1<<(w-1)));
	}else dfs(w-1,res);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) v1.push_back(a[i]);
	dfs(30,0);			
	return 0;
}
