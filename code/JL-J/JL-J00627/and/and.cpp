#include<bits/stdc++.h>
using namespace std;
int a[200000];
int op(int y,int f,int m,int n,int r){
    int o=0;
    r++;
    for(int i=f;i<m;i++){
        if(r==n-1) o=max(o,y&a[i]);
        else o=y&a[i];
        if(r!=n-1){
            o=max(o,op(o,f+1,m,n,r));
        }
    }
    return o;
}
int main(){
    freopen("and.in","r",std);
    freopen("and.out","w",std);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int q=0;
    for(int i=0;i<m;i++){
        q=max(q,op(a[i],i+1,m,n,0));
    }
    cout<<q;

















    return 0;
}
