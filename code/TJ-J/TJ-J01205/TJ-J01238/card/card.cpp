#include<bits/stdc++.h>
using namespace std;
int n,m,mx,t[500005],x[500005];
int f[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>f[i];
    	
	}
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++){
	    	t[f[j]]++;
	    	
	    	if(t[f[j]]>=2){
	    		for(int k=j-1;k>i;k--){
	    			f[t[j]]--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(t[i]>=1){
			    x[i]++;
			    t[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
