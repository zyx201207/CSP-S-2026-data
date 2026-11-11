#include<bits/stdc++.h>
using namespace std;
int n,m,vis[200001],maxx=0,a[200001],mst[1000001];
void dfs(int x,int sum,int o){
	if(x==m){
		maxx=max(maxx,sum);
		return ;
	} 
	for(int i=o;i<=n-m-x+1;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(sum!=0){
				mst[i]=1;
			dfs(x+1,(sum&a[i]),i);
			mst[i]=0;
		}else{
			mst[i]=1;
			dfs(x+1,a[i],i);
			mst[i]=0;
		}
			vis[i]=0;
		}
	}
	return ;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,1);
		cout<<maxx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				maxx=a[i];
			}else{
				maxx=(maxx&a[i]);
			}
		}
		cout<<maxx;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	//Trick||Treat!
	return 0;
}
