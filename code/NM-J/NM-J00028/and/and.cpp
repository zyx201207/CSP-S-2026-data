#include <iostream>
#include <cmath>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000100];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<max(n,m);
    return 0;
}
