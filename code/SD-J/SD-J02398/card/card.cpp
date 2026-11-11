#include<bits/stdc++.h>
using namespace std;
int n,m,b[500010],c[500010],a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0)b[a[j]]++;
			else{
				int o=j-1;
				while(a[o]!=a[j]){
					if(b[a[o]]>0){
						b[a[o]]-=1;
					}
					o--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j])c[j]++;
			
		}
		
		for(int j=1;j<=m;j++){
			b[j]=0;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

