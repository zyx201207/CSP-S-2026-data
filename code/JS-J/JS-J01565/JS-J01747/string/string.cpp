#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct h{
    int a;
    char c;
}h[20010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i].a>>h[i].c;
    }
    if(n==1){
        cout<<0;
    }
    if(n==2){
        if(h[1].a==h[2].a){
            cout<<0;
        }else{
            cout<<max(h[1].a,h[2].a)-(h[1].a+h[2].a)/2;
        }

    }
    return 0;
}
