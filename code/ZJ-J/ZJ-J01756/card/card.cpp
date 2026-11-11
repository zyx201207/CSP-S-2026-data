#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],f[N],vis[N],ans[N],k,p,tot=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	For(i,1,n) cin>>a[i];
	For(i,1,n) if(i<n && a[i]>a[i+1]) p=1;
	if(p==0){
		ans[1]=1;
		For(i,1,n-1){
			if(a[i]==a[i+1]) ans[tot]++;
			else ans[++tot]=i+1;
		}
	}
	else{
		For(i,1,n){
			k=0;
			memset(vis,0,sizeof(vis));
			For(j,i,n)
				if(vis[a[j]]==1){
					while(f[k]!=a[j]){
						vis[f[k]]=0;
						k--;	
					}
				}
				else{
					vis[a[j]]=1,f[++k]=a[j];
				}
			For(j,1,k) ans[f[j]]++;
		}
	}
	For(i,1,m) cout<<ans[i]<<" ";
	return 0;
}
/*
4 3 
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

10 5
1 1 1 1 2 2 2 3 4 5
*/