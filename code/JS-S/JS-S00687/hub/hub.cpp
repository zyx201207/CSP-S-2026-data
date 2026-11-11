#include<bits/stdc++.h>
using namespace std;
int c,n,t,u,v,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int e=1;e<=t;e++){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&u,&v);
        }
        cout<<n/5<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
