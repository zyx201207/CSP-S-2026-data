#include<bits/stdc++.h>
using namespace std;
long long a[200100],v[200100],t[200100],mt[200100],n,m,g[200100],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			memset(t,0,sizeof(t));
			memset(v,0,sizeof(v));
			memset(g,0,sizeof(g));
			for(int j=i;j<=n;j++){
				if(t[a[j]]==1){
					v[g[a[j]]]=1;
					for(int k=g[a[j]]+1;k<j;k++){
						if(!v[k]){
							v[k]=1;
							t[a[k]]--;
						}
					}
					g[a[j]]=j;
				}
				else{
					t[a[j]]++;
					g[a[j]]=j;
				}
			}
			for(int j=i;j<=n;j++){
				if(!v[j])mt[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<mt[i]<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)f=1;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			memset(v,0,sizeof(v));
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[j-1]){
					v[j-1]=1;
				}
			}
			for(int j=i;j<=n;j++){
				if(!v[j])mt[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<mt[i]<<" ";
		}
	}
}

