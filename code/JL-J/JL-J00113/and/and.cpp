#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    t=a[0];
    if(m==n){
        for(int i=0;i<n;i++)
            t=t and a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++)
            t=max(t,a[i]);
    }
    cout<<t;
    return 0;
}
// ^q^
