#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],p[500005],c[500005],z[300005],js=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	while(js<=n){
		int j=0;
		for(int i=0;i<=300000;i++){
			a[i]=0;
		}
		for(int i=js;i<=n;i++){
			if(a[p[i]]==0){
				a[p[i]]=1;
				j++;
				c[j]=p[i];
				
			}
			else if(a[p[i]]==1){
				a[p[i]]=0;
				int x=1;
				for(;x<=j;x++){
					if(x==p[i]){
						break;
					}
				}
				int y=x;
				for(;x<=j;x++){
					a[x]=0;
				}
				j=y;
			}
		} 
		for(int i=1;i<=j;i++){
			z[c[i]]++;
		}
		js++;
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<' ';
	}
	return 0;
}



