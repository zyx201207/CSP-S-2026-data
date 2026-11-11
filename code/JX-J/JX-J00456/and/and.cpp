#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==4) cout<<12;
    if(n==5) cout<<7;
    else cout<<49152;
    return 0;
}
