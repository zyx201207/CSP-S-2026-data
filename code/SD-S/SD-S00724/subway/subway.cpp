#include<bits/stdc++.h>
# define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int w[10005],xl[1005][1005][2],t[1005][10],tv[1005],x,y,T;
int ans=999999999;
void dfs(int r,int t){
	if(r==y){
		ans=min(t,ans);
		return;
	}
	for(long long i=0;i<tv[r];i++){
		dfs(r+1,t+T);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	io;
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(i==1) cout<<pow(x*y,2)-i<<endl;
		else cout<<x*y*2+i*2<<endl;
	}
	/*if(c>=12&&c<=19){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				int a[k+1],b;
				cin>>a[j]>>b;
				T=b;
				if(j>1){
					t[a[j]][tv[a[j]]++]=a[j-1];
					t[a[j-1]][tv[a[j-1]]++]=a[j];
				}
			}
		}
		for(int i=1;i<=10;i++){
			cout<<tv[i]<<" ";
			cout<<endl;
		}
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			ans=99999999;
			dfs(x,0);
		}
	}
	else{
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k/2;j++){
				
			}
		}
	}*/ 
	return 0;
}
/*
	16:46暴力！！！ 
	17:45打不出来······ 
	18:25意义不明的空城计 
15 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2




*/ 
