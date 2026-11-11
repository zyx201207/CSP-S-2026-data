#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x[200005],p=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[p]=x[i] and x[j];
            p++;
        }
    }
    int maxn=-1;
    for(int i=1;i<=p;i++){
        if(a[i]>maxn){
            maxn=a[i];
        }
    }
    cout<<maxn;
    return 0;
}
