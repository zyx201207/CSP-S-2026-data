#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int b=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1)b=0;
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++){
                b=max(a[i]&a[i+j],b);
            }
        }
    }
    else{
        for(int i=0;i<m-1;i++){
            b=a[i]&a[i+1];
        }
    }
    cout<<b;
    return 0;
}
