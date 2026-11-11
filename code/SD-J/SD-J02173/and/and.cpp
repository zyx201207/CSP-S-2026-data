#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[20005];
bool used[20005];
long long nm[20005];
long long maxl=0;
void dfs(int x,int start){
	if(x>=m){
		long long xmax=nm[0]; 
		for(int i=1;i<m;i++){
			xmax=xmax&nm[i];
		}
		if(xmax>maxl){
			maxl=xmax;
		}
		return;
	}
	for(int i=start;i<n;i++){
		nm[x]=a[i];
		dfs(x+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,0);
	cout<<maxl;
	return 0;
}
