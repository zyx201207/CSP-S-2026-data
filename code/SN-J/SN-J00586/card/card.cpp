#include<bits/stdc++.h>
using namespace std;
int s[100010];
int x[100010];

int main(){
	int n,m;
	cin>>n>>m;
	int y[m];
	int cnt=0;
	for(int i=0;i<=n;i++){
		x[n]=-1;
	}
	for(int i=0;i<m;i++){
		y[i]=0;
	}
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		s[i]=a;
		cnt++;
	}
	for(int i=1;i<=cnt;i++){
	    for(int j=0;j<=m-1;j++){
	    	for(int z=0;z<=m;z++){
	    		if(s[j]==x[z]){
	    			for(int p=z;p<=m;p++){
	    				x[p]=-1;
					}
				}
				for(int p=0;p<=m;p++){
					if(x[p]==-1){
						x[p]=s[j];
						break;
					}
				}
			}
			for(int z=0;z<=m;z++){
				y[x[z]]++;
			}	
		}
	} 
	for(int i=0;i<=m;i++){
		cout<<y[i]<<" ";
	}
	return 0;
}
