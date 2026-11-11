#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10000];
    int b;
    cin>>b;
    int q;
    for (int j=0;j<n;j++){
        if(a[j]>q){
            q=a[j];
        }
    }
    cout<<m;
    return 0;
}
