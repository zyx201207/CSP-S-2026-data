#include <bits/stdc++.h>
using namespace std;
long long m,n,c,d,q,w[10000010],t[10000010],k[1000010],a[1000010],r[100000010],ans,s[10000010],e[10000010],o[1000010],y[1000010];
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int g=1;
    for(int i=0;i<m;i++){
    cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=k[i-1];j<=k[i-1]+k[i];j++){
            cin>>a[j]>>t[j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>s[i]>>e[i];
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=k[g]+k[g-1];j++){
            if(s[i]==a[j]){
                ans+=t[j];
                int p=a[j];
            }
            if(e[i]==a[j]) ans+=t[j];
            o[i]=max(ans,o[i]);
            y[i]=min(ans,o[i]);
            g++;
        }
    }
    for(int i=1;i<=q;i++){
        cout<<y[i]<<"\n";
    }
    return 0;
}
