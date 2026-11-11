#include<bits/stdc++.h> 
using namespace std;
int a[100005];
int used[100005];
int ans=0;
void sy(int n,int m,int p){
	if(p>m){
		int x=a[used[1]];
		
		for(int i=2;i<=m;i++) {
			
			x=x&a[used[i]];
			
			
		}
		ans=max(x,ans);
		
		return ;
	}
	for(int i=used[p-1]+1;i<=n;i++){
		used[p]=i;
	 	sy(n,m,p+1);
	 	used[p]=0;
	 	
	}
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sy(n,m,1);
	cout<<ans;
	return 0;
}
