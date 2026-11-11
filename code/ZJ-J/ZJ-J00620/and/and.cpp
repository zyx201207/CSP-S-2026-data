#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[100001];
bool vis[100001];
int ans;
bool f1=true;
bool f2=true;
bool check(int x){
	for(int i=1;i<=20;i++){
		if(x+1==pow(2,i)){
			return 1;
		}
	}
	return 0;
}
void dfs(int x,int y,int s){
	if(y==m){
		ans=max(ans,s);
//		cout<<ans<<endl;
//		cout<<endl;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
//			cout<<a[i]<<" ";
			vis[i]=1;
			dfs(i,y+1,s&a[i]);
			vis[i]=0;
		}
		
		
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i])){
			f1=false;
		}
		if(a[i]!=i-1){
			f2=false;
		}
	}
	if(n<=20){//25pts
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(1,1,a[i]);
			vis[i]=0;
		}

		cout<<ans;
	}
	else if(m==1){//5pts
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==n){//5pts
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==2){//15pts
//	cout<<2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
//				cout<<a[i]<<" "<<a[j]<<" "<<(a[i]&a[j])<<endl;
			}
		}
		cout<<ans;
	}
	else if(m==n-1){//10pts
		int ans=0;
		for(int i=1;i<=n;i++){
			int xx;
			if(i==1) xx=a[2];
			else xx=a[1];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				xx&=a[j];
			}
			ans=max(ans,xx);
		}
		cout<<ans;
	}
	else if(f1){//5pts
		sort(a+1,a+n+1);
		for(int i=1;i<=m;i++){
			if(i==(n-m)+1){
				cout<<a[i];
				break;
			}
		}
	}
	else if(f2){//10pts
		cout<<n-m;
	}
}
