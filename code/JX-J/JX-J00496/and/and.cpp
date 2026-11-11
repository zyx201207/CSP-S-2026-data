#include<bits/stdc++.h>
using namespace std;
long long n,m,ys[200013],maxx=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ys[i];
        maxx=max(maxx,ys[i]);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    maxx=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if((ys[i]&&ys[j])>maxx)maxx=ys[i]&&ys[j];
        }
    }
    cout<<maxx;
    return 0;
}
