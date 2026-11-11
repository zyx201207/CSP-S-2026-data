#include <bits/stdc++.h>
using namespace std;
long long d[599999];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long> a(n+5,0),b(m+5,0),c(n+5,0),ans(m+5,0);//a为原值 b为标记 c为后面第一次出现
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]=a[i-1]) d[i-1]-=i;
    }
//    for(long long i=n;i>=1;i--){
//  //      cout<<b[a[i]]<<" ";
//        c[i]=b[a[i]];
//        b[a[i]]=i;
//    }
//    for(long long i=1;i<=n;i++){
//        cout<<c[i]<<" ";
//    }
//    for(long long i=1;i<=n;i++){
//        int s=i-1;
//        while(s<n){
//            s++;
//            if(c[i]==0) ans[a[i]]+=1;
//            else {
//                s=c[i];
//                cout<<c[i];
//            }
//        }
//    }
//    for(int i=1;i<=m;i++){
//        cout<<ans[i]<<" ";
//    }
    for(long long i=1;i<=n;i++) cout<<d[i]+i<<" ";
    return 0;
}
