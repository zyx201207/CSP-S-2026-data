#include<bits/stdc++.h>
using namespace std;
int res=0,n,d,ans=0; 
int brr[2000005],arr[2000005];
bool vis[2000005];
void dfs(int dep,int x,int v){
	if(dep>x){
		if(abs(arr[brr[dep-1]]-arr[v])<=d){
			res++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i] && abs(arr[i]-arr[brr[dep-1]])<=d){
			vis[i]=1;
			brr[dep]=i;
			dfs(dep+1,x,v);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>arr[i]; 
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(arr[j]-arr[i])<=d){
					continue;	
				}
				brr[1]=i;
				vis[i]=1;
				for(int k=1;k<=n-2;k++){
					res=0;
					dfs(2,k,j);
					if(res>0){
						if(res==2){
							ans++;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

