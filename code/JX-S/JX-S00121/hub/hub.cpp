#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,minn=0x3f3f3f3f;
    scanf("%d %d",&c,&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n-1;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            minn=min(minn,a);
            minn=min(minn,b);
        }
        cout<<minn<<"\n";
    }
    return 0;
}
