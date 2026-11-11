#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
    int n,m,s,maxn=-1,p,t;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    p=m;
    s=a[1];
    for(int i=1;i<=n+1-m;i++){
        while(p!=1){
            s=s&a[i+p-1];
            p--;
        }
        p=m;
        maxn=max(s,maxn);
        s=a[i+1];


    }
    cout<<maxn;
    return 0;
}
