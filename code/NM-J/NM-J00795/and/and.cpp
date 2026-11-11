#include<bits/stdc++.h>
using namespace std;;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,b;
    cin>>n>>b;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n/2];
    return 0;
}
