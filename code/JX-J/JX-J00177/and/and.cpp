#include <iostream>
using namespace std;
int a[1005];
int b[1005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){

             b[i]=a[j]&a[i];

        }

        sum=0;

    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(b[i]>maxn) maxn=b[i];
    }
    cout<<maxn;

    return 0;
}
