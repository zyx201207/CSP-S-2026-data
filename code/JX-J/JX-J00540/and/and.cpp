#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[10000005],b[10000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=m){
            b[i]=a[i];
            for(int j=i-1;j>i-m;j--){
                b[i]=a[j]&b[i];
            }
        }
    }
    int maxa=-1e9;
    for(int i=1;i<=n;i++){
        if(maxa<b[i]){
            maxa=b[i];
        }
    }
    cout<<maxa;



    return 0;
}
