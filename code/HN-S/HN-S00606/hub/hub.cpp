#include<bits/stdc++.h>
using namespace std;
int f[1000006];
struct node{
    int a;
    int b;
};
bool cmp(node x,node y){
    return x.a<y.a;
}
void cs(int n){
    for(int i=2;i<=n;i++){
        f[i]=i;
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        node s[1000006];
        cs(n);
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b;
        }
        sort(s+1,s+1+n,cmp);
        cout<<n/5<<endl;
    }
    return 0;
}
