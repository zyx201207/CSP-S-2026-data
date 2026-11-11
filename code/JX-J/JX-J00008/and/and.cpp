#include <bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ma=0,k;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        k=a[n];
        m+=i;
        if(m>n){
            m=n;
        }
        for(int j=i+1;j<m;j++){
            k=(k&a[j]);
        }
        ma=max(ma,k);
    }
    cout <<ma;
    return 0;
}
