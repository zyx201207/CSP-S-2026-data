#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],b[M]={0},c[M];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int y=1;
	int ans=0;
	while(y<=n){
		for(int j=1;j<=m;j++){
		   	f[j]=0;
		   	c[j]=0;
	    }
	    int sum=y;
	    for(int i=y;i<=n;i++){
		    if(f[a[i]]==0){
		    	f[a[i]]=1;
		    	c[a[i]]=i;
			}else{
				for(int j=c[a[i]];j<i;j++){
		   	        f[a[j]]=0;
	            }
				f[a[i]]=1;
			}
    	}	
    	for(int i=1;i<=m;i++){
    		if(f[i]){
    			b[i]++;
			}
		}
		y++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
