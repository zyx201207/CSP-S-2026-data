#include<bits/stdc++.h>
using namespace std;
int a[5000010],b;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long maxx=-0x3f3f3f3f;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]|a[j]>maxx){
                maxx=(a[i]|a[j]);
            }
        }
    }
    cout<<maxx;
    return 0;
}
