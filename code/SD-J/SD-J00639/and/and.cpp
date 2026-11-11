#include<bits/stdc++.h>
using namespace std;
int n,m,a[200006],maxx=INT_MIN,b[200006];
int awy(int x,int y){
	int a1[30]={0},a2[30]={0},idx1=0,idx2=0,sum=0;
	while(x!=0){
		a1[idx1++]=x%2;
		x/=2;
	}while(y!=0){
		a2[idx2++]=y%2;
		y/=2;
	}for(int i=0;i<=max(idx1,idx2)-1;++i){
		int t=0;
		if(a1[i]==1&&a1[i]==a2[i]) t=1;
		sum+=pow(2,i)*t;
	}return sum;
}void dfs(int idx,int step){
	if(step==m){
		int sum=b[1];
		for(int i=1;i<=m;++i){
			sum=awy(b[i],sum);
		}maxx=max(maxx,sum);
		return;
	}if(idx==n+1&&step!=m) return;
	b[step+1]=a[idx];
	dfs(idx+1,step+1);
	b[step+1]=0;
	dfs(idx+1,step);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}dfs(1,0);
	cout<<maxx;
	return 0;
}
