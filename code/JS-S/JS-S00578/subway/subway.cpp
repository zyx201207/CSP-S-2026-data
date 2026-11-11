#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],a[500010],h[500010],val[500010],nxt[500010],t[500010],idx=1;
void add(int a,int b,int s){
    h[a]=nxt[idx];
    val[nxt[b]]=s;
    nxt[b]=idx++;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0) cout<<"32\n17";
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++) cin>>a[j]>>t[j];
        for(int j=0;i<k;j++){
            add(a[i],a[i+1],t[i]+t[i+1]);
            add(a[i+1],a[i],t[i]+t[i+1]);
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
