#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],h[500010],d[500010],s=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
	scanf("%lld",&a[i]);
	h[a[i]]++;
	}
	//for(int z=1;z<=m;z++){
	    //for(int i=1;i<=n;i++){
	    //	d[s]=a[i];
	    	//for(int j=1;j<=s;j++) {
			//    if(d[j]==d[s]){
	    	//	    for(int x=j+1;x<=s;x++) d[x]=0;
	    	//	    s=j;
	    	//	    break;
			 //   }
		//	}
		//	for(int j=1;i<=s;j++) h[d[j]]++;
		//	s++;
	//	}
//	}
	for(int i=1;i<=n;i++) printf("%lld ",h[a[i]]);
	return 0;//愿天堂没有STL,可我昨天刚看过
}
