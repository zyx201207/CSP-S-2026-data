#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],max1,t;
void f(int t,int m,int n){
    if(m==0){
        max1=max(max1,t);
        return;
    }
    for(int i=1;i<=n;++i){
        if(b[i]==0){
            b[i]=1;
            f(t&a[i],m-1,n);
            b[i]=0;
        }

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        b[i]=1;
        f(a[i],m-1,n);
        b[i]=0;
    }
    cout<<max1<<"\n";
    return 0;
}

