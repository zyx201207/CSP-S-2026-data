#include<bits/stdc++.h>
using namespace std;
int a[200020];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int maxx=-1;
    if(m==1){
        cout<<a[n-1];
    }
    else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxx=max(a[i]&a[j],maxx);
            }
        }
        cout<<maxx;
    }
    else if(m==n){
        int o=a[0];
        for(int i=1;i<n;i++){
            o=o&a[i];
        }
        cout<<o;
    }
    else{
        int p=a[n-m];
        for(int i=n-m+1;i<n;i++){
            p=p&a[i];
        }
        cout<<p;
    }
    return 0;
}
