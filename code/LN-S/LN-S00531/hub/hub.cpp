#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
bool ch(int x){
    if(x<=0) return false;
    int p=n;
    p-=x*2+1;
    p-=k-2;
    return (p+1)/2+1<=x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    int u,v;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;++i){
            cin>>u>>v;
        }
        if(k>=n){
            printf("0\n");
            continue;
        }else if(k>=n-2){
            printf("1\n");
            continue;
        }
        n=n/2+1;
        if(ch(((n-k)/4-1))){
            printf("%d\n",(n-k)/4-1);
        }else if(ch(((n-k)/4))){
            printf("%d\n",(n-k)/4);
        }else if(ch((n-k)/4+1)){
            printf("%d\n",(n-k)/4+1);
        }else {
            printf("%d\n",(n-k)/4+2);
        }
    }
    return 0;
}

