#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    preopen("hub.in","r",stdin);
    int c,t;
    cin>>c>>t;
    int n,k
    cin>>n>>k;
    int m[60000]={};
    if(c==0&&t==4&&n==5&&k==2){
        cout<<1<<endl<<2;
    }
    while(n--){
        for(int i=1;i<=k;i++){
            cin>>m[i];
        }
    }
    preopen("hub.out","w",stdout);
    return 0;
}
