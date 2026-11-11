#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
int sum=0;
void dfs(int x,int ans,int q){
	if(ans>=m){
	    if(ans==m){
		    sum=max(sum,q);
	    }	
	    return ;
	}
	if(m-ans>n-x+1){
		return ;
	}
	if(x==n+1){
	    sum=max(sum,q);
		return ;
    }
    dfs(x+1,ans,q);
    if(ans==0){
		q=a[x];
	}else{
		q=(q&a[x]);
	}
	dfs(x+1,ans+1,q);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		} 
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int sun=(a[i]&a[j]);
				sum=max(sum,sun);
			}
		} 
		cout<<sum;
		return 0;
	}
	dfs(1,0,0);
	cout<<sum;
	return 0;
} 
