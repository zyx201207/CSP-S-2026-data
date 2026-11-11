#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int a,l=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        if(i<2){
            l+=a;
        }
    }
    if(l<0){
        l=l*(-1)
    }
    cout<<l;
    return 0;
}
