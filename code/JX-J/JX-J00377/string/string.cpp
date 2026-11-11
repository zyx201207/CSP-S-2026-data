#include <bits/stdc++.h>
using namespace std;
struct zf{
    int shu;
    char zm;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,p=0;
    cin>>n;
    zf a[200005]={};
    for(int i=1;i<=n;i++){
        cin>>a[i].shu>>a[i].zm;
    }
    for(int i=1;i<n;i++){
        if(a[i].zm!=a[i+1].zm){
            p=1;
        }
    }
    if(p==0){
        cout<<0;
    }
    return 0;
}
