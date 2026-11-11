#include <bits/stdc++.h>
using namespace std;
int a[1000010],memory[1000010],n,m,maxx,max1;
int dfs(int sum,int l){
	if(l>m){
		return sum;
	}
	for(int i=1;i<=n;i++){
		if(memory[i]==1)continue;
		memory[i]=1;
		max1=max(max1,dfs(sum&a[i],l+1));
		memory[i]=0;
//		cout<<"Max="<<max1<<" Now="<<sum<<endl;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(memory,0,sizeof(memory));
		memory[i]=1;
		dfs(a[i],1);
		maxx=max(maxx,max1);
	}
	cout<<maxx;
	return 0;
}