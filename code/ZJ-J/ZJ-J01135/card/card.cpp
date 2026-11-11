#include <bits/stdc++.h>
using namespace std;
int n,m,i,fl,j,t,cs,b[500010],a[500010],f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;cs=1;
    for(i=1;i<=n;i++) cin>>a[i];
    while(cs<=n){
    	for(i=cs;i<=n;i++){
    	    for(j=1;j<=t;j++)
    		    if(b[j]==a[i]){
    			   t=j-1;break;
			    }
			b[++t]=a[i];
	    }
	    for(i=1;i<=t;i++) f[b[i]]++;
	    cs++;t=0;
	}
	for(i=1;i<=m;i++) cout<<f[i]<<" ";
}
