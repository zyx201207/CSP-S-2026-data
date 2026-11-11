#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000010],k[1000],a[1000][100010],t[1000][100010],x[100001],y[100001];
long long much[1000],who[1000][1000],how[1000][1000],ans,d1,d2,adm,ro;
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int i=0;
	while(i<q){
		for(int l=0;l<n;l++){
		    for(int j=0;j<k[i];j++){
		    	if(a[l][j]==x[i]){
		    		d1=j;adm++;
		    	}
		    	if(a[l][j]==y[i]){
		    		d2=j;adm++;
		    	}
	    	}
	    	if(adm==2){
	    		ro=l;break;
	    	}
	    	adm=0;
	    }
		ans=w[x[i]]+t[ro][d1]+t[ro][d2]+w[y[i]];cout<<ans;
		i++;
}

	return 0;
} 