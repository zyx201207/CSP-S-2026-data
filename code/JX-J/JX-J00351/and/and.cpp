#include<bits/stdc++.h>
using namespace std;
int n,m,mx=-1;
int a[200002];
void dp(int x,int d){
    x--;
    d&=a[m];
    dp(x,d);
    if(x==0){
        if(d>mx)mx=d;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[n];
    dp(m,0);
    cout<<mx;
    return 0;
}
