#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int start;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
    for(int i=1;i<=n-1;i++){
            start=a[1];
        start&=a[i+1];
    }
    }
    cout<<start;
    return 0;
}
