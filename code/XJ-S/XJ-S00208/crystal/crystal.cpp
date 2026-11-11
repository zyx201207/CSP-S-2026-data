#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
long long int n,m;
long long int maxn=-1,cnt=1;
long long int a[N],b[N];
long long int dp[N][N];
long long int vis[N];
int fun(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i){
				continue;
			}
			if(a[i]==a[j]&&vis[i]==0&&vis[j]==0){
				cnt+=1;
				vis[i]=vis[j]=1;
			}
			
		}
	}
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	
	for(int i=1;i<=n;i++){
		long long int num=m;
		for(int j=1;j<=m;j++){
			long long int uk=j;
			for(int k=1;k<=n;k++){
					if(uk-1>=0){
					a[i]+=1;
					uk-=1;
				}
				
			}
			
			fun(j);
			for(int x=1;x<=n;x++){
			    a[x]=b[x];
			    vis[x]=0;
		    }
		}	
		maxn=max(maxn,cnt);
		cnt=1;
	}
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}   
