#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[500005],p,c;
bool zd;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c=i;
		p=a[c];
		while(c<=n){
			if(c==n){
				vis[a[n]]++;
				break;
			}
			zd=0;
			for(int j=n;j>c;j--){
				if(a[j]==p){
					zd=1;
					vis[p]++;
					c=j+1;
					p=a[c];
				}
				if(zd==0){
					vis[a[c]]++;
					c+=1;
					p=a[c];
					
				}
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<vis[i]<<' ';
	}
	return 0;
}
