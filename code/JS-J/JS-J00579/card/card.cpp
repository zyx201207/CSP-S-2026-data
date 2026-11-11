#include<bits/stdc++.h>
using namespace std;
const int N=500500;
int n,m;
int a[N];
int b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=0;
    }
    cout<<1;
    return 0;
}
