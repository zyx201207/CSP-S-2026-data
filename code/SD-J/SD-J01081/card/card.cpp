#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int x[n+1],s[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		int v[n+1]={0},z[m+1]={0};
		for(int j=i;j<=n;j++){
			v[j]=x[j];
			if(z[v[j]]==0){
				z[v[j]]=j;
			}
			else{
				for(int u=z[v[j]];u<j;u++){
					z[v[u]]=0;
					v[u]=0;
				}
				z[v[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(z[j]!=0){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
