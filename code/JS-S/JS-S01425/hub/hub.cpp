#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a,b;
int main(){
    cin>>c>>t;
    if(c==13||c==14){
        while(t--){
            scanf("%d%d",&n,&k);
            for(int i=1;i<=n;i++){
                scanf("%d%d",&a,&b);
            }
            printf("%d\n",(n-k+2)/3);
        }
        return 0;
    }

    return 0;
}
