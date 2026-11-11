#include <bits/stdc++.h>
using namespace std;
int n,m,a[500011],b=1,d=0;
bool c[500011];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        c[i]=false;
    }
    for(int j=1;j<=m;++j){
        for(int k=1;k<=n;++k){
            if(a[b]>a[k]){
                b=k;
            }
        }
        a[b]+=1;
    }
    for(int i=1;i<=n;++i){
        for(int l=i+1;l<=n;++l){
            if(a[i]==a[l] && c[i]==false && a[i]==a[b]){
                d++;
                c[l]=true;
            }
        }
    }
    cout<<++d;
    return 0;
}
