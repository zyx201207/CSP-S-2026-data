#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[100000],sum,c[100000];
    char b[100000];
    for (int i=0;i<n;i++){
        cin>>a[i];
        c[n-i]=a[i];
        sum+=a[i];
        cin>>b[i];
    }
    if(set(b).size()==1){
        cout<<0;
    }
    return 0;
}
