#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    int tail=0;
    int ans=0;
    for(int i=30;i>=0;--i){
    	for(int j=1;j<=n;++j){
    		if(a[j]&(1<<i)){
    			b[++tail]=a[j];
			}
		}
		if(tail>=m){
			memcpy(a,b,sizeof(b));
			ans+=(1<<i);
			n=tail;
		}
		tail=0;
	}
	printf("%d",ans);
    return 0;
}
