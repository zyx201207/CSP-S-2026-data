#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            long long num=a[i];
            for(int j=i+1;j<=n;j++){
                if((num & a[j])>maxn){
                    maxn=(num&a[j]);
                }
            }
        }
        cout<<maxn;
    }else{
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    return 0;
}
