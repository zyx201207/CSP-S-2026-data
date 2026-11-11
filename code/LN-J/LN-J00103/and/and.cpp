#include<bits/stdc++.h>
using namespace std;
int n,m,mx;
int a[200005];
void dg(int t,int b,int i){
    if(b<=mx) return ;
    if(t==0){
        mx=max(mx,b);
        return ;
    }
    for(i;i<n-t+1;i++){
        if(a[i]<=mx){
            n=i+1;
            return;
        }
        dg(t-1,a[i]&b,i+1);
        if(a[i]<=mx){
            n=i+1;
            return;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    dg(m,INT_MAX,0);
    cout<<mx;
    return 0;
}
