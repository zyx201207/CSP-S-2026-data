#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long arr[N];
long long mi=3e18;
long long ge=0;
void dfs(int x,int y,int l,int d,int cid,int ci){
	if(x==y){
		l+=cid*ci;
		if(l<mi){
			mi=l;
			ge=1;
		}else if(l==mi){
			ge++;
		}
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(i==x+1&&arr[i]-arr[x]<=d) dfs(x+1,y,l,d,cid+1,ci+1);
		else if(arr[i]-arr[x]<=d) dfs(i,y,l+(arr[i]-arr[x]),d,cid,ci+1);
	}
}
void baoli(){
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ge=0;
			mi=1e18;
			dfs(i,j,0,d,0,0);
			if(ge==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c<=2){
		int _;
		cin>>_;
		while(_--){
			baoli();
		}
	}else{
		int _;
		cin>>_;
		while(_--){
			cout<<0<<endl;
		}
	}
	return 0;
}
