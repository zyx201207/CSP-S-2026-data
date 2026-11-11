#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,nn[10000],maxa=-1,a;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nn[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            a=nn[i]&nn[j];
            if(a>maxa){
                maxa=a;
            }
        }
    }
    cout<<maxa;
    return 0;
}
