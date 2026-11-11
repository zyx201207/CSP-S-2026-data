#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,c=0;
    int a[100005],b[100005],d[10005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]>a[1]){
        b[c]=a[1];
        c++;
    }
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1] && b[c-1]!=a[i]){
            b[c]=a[i];
            c++;
        }
    }
    for(int i=0;i<m;i++){
        d[i]=b[c-m];
    }
    int e=0;
    for(int i=0;i<m;i++){
        e=d[i] and d[m-i];
    }
    cout<<e;
    return 0;
}
