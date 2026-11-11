#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,d;
int sum;
int a[2000010];
void dfs(int x,int y,int step,int minlen){
	if(x==y){
		if(step=minlen) sum++;
		return ;
	}
	int idx=x+1;
	while(a[idx]-a[x]<=d){
		dfs(idx,y,step+1,minlen);
		idx++;
	}
}
int Minlen(int x,int y){
	int sum=0;
	while(x<=y){
		int idx=x+1;
		while(a[idx]-a[x]<=d&&idx<=y) idx++;
		if(x==idx-1) return -1;
		x=idx-1;
		sum++;
	}
	return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				sum=0;
				int minlen=Minlen(i,j);
				cout<<minlen<<'\n';
				if(minlen!=-1) dfs(i,j,0,minlen);
				if(sum==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
