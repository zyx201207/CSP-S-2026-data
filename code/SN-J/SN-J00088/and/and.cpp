#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]>=i-1){
            m=i;
        }
    }
    m=a[m/2+1];
    cout<<m;
    return 0;
}




