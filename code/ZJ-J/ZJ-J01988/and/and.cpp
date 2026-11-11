#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],ma;
void dfs(int k,int cnt){
	if(k==n+1){
		if(cnt==m){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(f[i]){
					if(sum==0)sum=a[i];
					else sum=sum&a[i];
				}
			} 
			ma=max(ma,sum);
		}
		return;
	}
	f[k]=1;
	dfs(k+1,cnt+1);
	f[k]=0;
	dfs(k+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	cout<<ma;
	
	return 0;
}
