#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
const int INF=2e18,N=2e5+10;
int n,m,a[N],mx=-INF,ans=-INF;
void dfs(int d,int y,int num){
	if(y>=m){
		ans=max(ans,num);
		return ;
	}
	if(d>=n){
		return ;
	}
	for(int i=d+1;i<=n;i++){
		if(num==-1) dfs(i,y+1,a[i]);
		else dfs(i,y+1,num&a[i]);
	}
}
signed main(){
	IOS;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	else if(m==n){
		int cnt=a[1];
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	else if(n<=20){
		dfs(0,0,-1);
		cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
} 
