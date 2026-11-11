#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],p[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			int u=j+1,k=a[j];
			while(a[u]!=k&&u<=n)u++;
			if(u>n){p[a[j]]++;j++;}
			else j=u;
		}
	}
	for(int i=1;i<=m;i++)cout<<p[i]<<" ";
}
