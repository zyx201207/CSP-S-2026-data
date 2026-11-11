#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],nnow[200005];
bool vis[200005];
int mmax=INT_MIN;
void dfs(int s){
	if(s==m){
		int mm=INT_MAX,sum=0;
		for(int i=1;i<=n;i++){
			if(nnow[i]==1) {
				mm=mm&a[i];
				sum++;
			}
		}
		if(sum==m&&mm>mmax)mmax=mm;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=1;j++){
			if(!vis[i]){
				vis[i]=1;
				nnow[i]=j;
				dfs(s+1);
				nnow[i]=0;
				vis[i]=0;
			}
		}
	}
}
int main(){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1];
	}
	else if(m==n){
		mmax=a[1];
		for(int i=2;i<=n;i++){
			mmax=mmax&a[i];
		}
		cout<<mmax;
	}
	else if(n>2000){
		mmax=a[1];
		for(int i=2;i<=m;i++){
			mmax=mmax&a[i];
		}
		cout<<mmax;
	}
	else{
		dfs(0);
		cout<<mmax;
	}
	return 0;
} 
