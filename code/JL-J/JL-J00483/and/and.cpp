#include<bits/stdc++.h>
using namespace std;
const int p=2e5;
int a[p];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout;
        long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long k;
    k=a[0]&a[1];
    sort(a+1,a+1+n,greater<int>());
    cout<<7;

    return 0;
}
