#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200010],maxa=0,yu,yu1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        if(i==0)yu=a[i];
        else yu&=a[i];
    }
    if(m==1){cout<<maxa;return 0;}
    if(m==n){cout<<yu;return 0;}
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i])swap(a[j],a[i]);
        }
    }
    for(int i=0;i<m;i++){
        if(i==0)yu1=a[i];
        else yu1&=a[i];
    }
    cout<<yu1;
    return 0;
}
