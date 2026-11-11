#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a[10000],b=0,c=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        b=a[i]^a[i+1];
        c=b;
        if(b<c){
            b=c;
        }
    }
    cout<<b;
    return 0;

}
