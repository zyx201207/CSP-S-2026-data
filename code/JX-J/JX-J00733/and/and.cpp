#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma=0,t;
    int a[21]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        t=(m&a[i]);
        if(t>ma){
           ma=t;
        }
    }
    cout<<t;
    return 0;
}
