#include<bits/stdc++.h>
using namespace std;
int a[1050000],maxn[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        long long maxs=-1,maxa;
        for(int j=1;j<=n;j++){
            if(a[j]>maxs){
                maxs=a[j];
                maxa=j;
            }
        }
        maxn[i]=maxs;
        a[maxa]=-1;
    }
    long long ans=maxn[1];
    for(int i=2;i<=m;i++){
        ans=ans&maxn[i];
    }
    cout<<ans;
    return 0;
}
