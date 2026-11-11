#include<bits/stdc++.h>
using namespace std;
int a[500010],p[500010],sc[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(sc,0,sizeof(sc));
	int n,m;
	cin>>n>>m;
	int ans=0, ok=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		memset(p,0,sizeof(p));
		int ans=0,ok=0;
		
		for(int j=i; j<=n; j++){
			ok=0;
			for(int k=1; k<=ans; k++){
				if(p[k]==a[j]){
					for(int l=1; l<=ans; l++){
						p[l]=0;
					}
					ans=1;
					p[1]=a[j];
					ok=1;
					break; 
				}
			}	
			if(ok==0){
				p[++ans]=a[j];
				
			} 
		}
		for(int h=1; h<=ans; h++){
			sc[p[h]]++;
		}
	}
	for(int i=1; i<=m; i++){
		cout<<sc[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
