#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50002];
int c[50003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int hh=1;hh<=n;hh++){
		int b[50002]={},tot=0;
		int now[50002]={};
		for(int i=hh;i<=n;i++){
			if(now[a[i]]==0){
				now[a[i]]++;
				b[++tot]=a[i];
			}else{
				for(int j=1;j<=tot;j++){
					if(b[j]==a[i]){
						for(int k=j;k<=tot;k++){
							now[b[k]]--;
						}
						tot=j-1;
						break;
					}
				}
				b[++tot]=a[i];
				now[a[i]]++;
			}			
		}
		for(int i=1;i<=m;i++){
			if(now[i]!=0){
				c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
