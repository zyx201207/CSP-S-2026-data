#include<bits/stdc++.h>
using namespace std;
int n,m;
int g,t;
int a[1000];
int b;
int h[1000];
int y[1000][1000];
int o[1000];
int u[1000];
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);	
cin>>n>>m;
g=1;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=100;j++){			
			y[i][j]=a[i]%2;
			a[i]=a[i]/2;
			o[i]++;
			if(a[i]==1){
				break;
				}
			}				
	}
	h[1]=2;
	for(int i=2;i<=15;i++){
		h[i]=h[i-1]*2;
		}
	for(int i=1;i<=n;i++){
		for(int j=1,l=1;j<=n,l<=o[i];j++,l++){
		if(y[i][j]==y[l][j]&&y[i][j]==1){
			u[t]+=h[j];
			}
		t++;
		}		
	}
	sort(u+1,u+t+1);
	cout<<u[t];
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

