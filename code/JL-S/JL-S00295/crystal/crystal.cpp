#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],t[10010],ma=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        t[i-1]=a[i]-a[i-1];
    }
    for(int i=1;i<=n-1;i++){
        int x=0,f=0,l=i,r=1;
        while(x<=m&&l<n&&i<n){
            x=x+r*t[l];
            f++;
            l++;
            r++;
        }
        if(f>ma)
            ma=f;
    }
    cout<<ma;
    return 0;
}
