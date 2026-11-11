#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int maxn=0,mi=0,mj=0,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int k=m-1;
    for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]&a[j]>maxn&&i!=j){
                    maxn=(a[i]&a[j]);
                    mi=i;
                    mj=j;
                }
            }
        }
        a[mi]=0;
        a[mj]=0;
        mi=0,mj=0;
        ans=maxn;
        ans=(ans&maxn);
        maxn=0;
        k--;
    while(k--){
        for(int i=1;i<=n;i++){
                if(a[i]&ans>maxn){
                    maxn=(a[i]&ans);
                    mi=i;
                }

        }
        a[mi]=0;
        mi=0;
        ans=(ans&maxn);
        maxn=0;
    }
    cout<<ans;
    return 0;
}

