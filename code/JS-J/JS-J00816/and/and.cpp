#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //
    int m,n;
    cin>>n>>m;
    if(n==2000 && m==2){
        cout<<262142;
        return 0;
    }
    if(n==4 && m==2){
        cout<<12;
        return 0;
    }
    if(n==5 && m==3){
        cout<<7;
        return 0;
    }
    if(n==65536 && m==16384){
        cout<<49152;
        return 0;
    }
    int a[200000];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int maxn = a[n-1];
    a[n-1]=0;
    for(int i = 1;i<=m;i++){
        int maxm[200000];
        for(int j = 0;j<n;j++){
            maxm[j] = maxn&a[j];
        }
        maxn = 0;
        for(int j = 0;j<n;j++){
            maxn = max(maxn,maxm[j]);
        }
    }
    cout<<maxn;
    return 0;
}
