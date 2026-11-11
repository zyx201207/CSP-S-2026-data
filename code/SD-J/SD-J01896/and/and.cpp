#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],m,maxn,maxn2,ans,sum;
long long lmax(long long c,long long d){
	if(c>=d){
		return c;
	}
	else{
		return d;
	}
}
void dfs(int x,long long y,int idx){
	if(x>=n || idx==m){
		if(idx==m){
			//cout<<y<<endl;
			maxn=lmax(maxn,y);
			
		}
		return ;
	}
	if(idx==0){
		dfs(x+1,a[x+1],idx+1);
		dfs(x+1,y,idx);
	}
	else{
		dfs(x+1,y&a[x+1],idx+1);
		dfs(x+1,y,idx);
	}
	
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn2=lmax(a[i],maxn2);
		if(i==1){
			ans=a[1];
		}
		else{
			ans=ans&a[i];
		}
	}
	if(m==1){
		cout<<maxn2;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=lmax(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	dfs(0,0,0);
	cout<<maxn;
	return 0;
} 
