#include<bits/stdc++.h>
using namespace std;
int c , t , n , k , u , v ;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
        }
        if(k==n) printf("0\n");
        else if(k>n/2) printf("1\n");
        else printf("%d\n",n/2-k+1);
    }
    return 0;
}
