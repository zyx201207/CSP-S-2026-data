#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,T;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    //printf("%d %d",c,T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
        }
        printf("%d\n",((((n+1)>>1)-m+3)>>2)+1);
    }
    return 0;
}
