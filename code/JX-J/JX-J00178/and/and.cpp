#include <bits/stdc++.h>
using namespace std;
int n,m,a[2000005];


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b,c=0,cnt;
    while(1){
        for(int l=1;l<m-2;l++){
            for(int j=0;j<m-1;j++){
            b=a[j]&a[l];
            cnt=max(b,c);
            c=b;
            }
        }
    }
    cout<<cnt;
    return 0;
}
