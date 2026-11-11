#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=-1;
    cin>>n>>m;
    if(m==1){
        int x;
        for(int i=1;i<=n;i++){
            cin>>x;
            maxn=max(maxn,x);
        }
        cout<<maxn;
        return 0;
    }if(m==2){
        int a[2010];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                maxn=max(maxn,(a[i]&a[j]));
            }
        }
        cout<<maxn;
        return 0;
    }if(m==n){
        int x;
        for(int i=1;i<=n;i++){
            cin>>x;
            maxn=(maxn&x);
        }
        cout<<maxn;
        return 0;
    }
    return 0;
}
