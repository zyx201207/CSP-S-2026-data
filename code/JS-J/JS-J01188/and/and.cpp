#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int o[1000100];
    for(int i=0;i<a;i++){
        cin>>o[i];
    }
    cout<<o[a-1];
    return 0;
}
