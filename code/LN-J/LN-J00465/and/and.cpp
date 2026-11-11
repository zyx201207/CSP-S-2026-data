#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200100],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    ans=max((a[i]&a[j]),ans);
                }
            }
        }
        cout<<ans;
    }else{
        for(int i=1;i<=m-1;i++){
            ans=(a[i]&a[i+1]);
        }
        cout<<ans;
    }
    return 0;
}
