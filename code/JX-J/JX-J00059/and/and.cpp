#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],s,mx,smx,vis[200002];
void dfs(long long x,int k,int sy)
{
    if(sy==0){
        smx=max(smx,x);
        return ;
    }
    for(int i=k+1;i<=n;i++){
        dfs(x&a[i],i,sy-1);
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==n){
        for(int i=2;i<=n;i++) s=a[i]&a[i-1];
        cout<<s;
        	fclose(stdin);
	fclose(stdout);
        return 0;
	}
	if(m==1){
        cout<<mx;
        	fclose(stdin);
	fclose(stdout);
        return 0;
	}
	if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                smx=max(smx,a[i]&a[j]);
            }
        }
        cout<<smx;
                	fclose(stdin);
	fclose(stdout);
        return 0;
	}
	for(int i=1;i<=n-m+1;i++){
        memset(vis,0,sizeof(vis));
        dfs(a[i],i,m-1);
	}
	cout<<smx;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
