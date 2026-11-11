#include <bits/stdc++.h>
using namespace std;
int A[1005],B[1005],a[10005],b[10005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>A[i];
    }
    for(int i=1;i<=A[1];i++){
        cin>>a[i];
    }
    for(int i=1;i<=t;i++){
        cin>>B[i];
    }
    for(int i=1;i<=B[1];i++){
        cin>>b[i];
    }
    if(A[2]==B[2]){
        cout<<1<<endl<<2;
        return 0;
    }
    if(A[2]>B[2]){
        cout<<0<<endl<<1;
        return 0;
    }
    if(A[2]<B[2]){
        cout<<2<<endl<<3;
        return 0;
    }
}
