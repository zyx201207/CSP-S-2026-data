#include<bits/stdc++.h>
using namespace std;
int c,n;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&n);
    for(int o=1;o<=n;o++){
        int l,r;scanf("%d%d",&l,&r);
        for(int i=1;i<=n;i++){
            int a,b;scanf("%d%d",&a,&b);
        }
        if(r%2==1) printf("%d\n",r/2+1);
        else printf("%d\n",r/2);
    }
    return 0;
}
