#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    int n,m=0,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int s,t;
        s=a[i]&a[i+1];
        t=a[0]&a[i+1];
        if(s>m) m=s;
        if(t>m) m=t;
    }
    return 0;
}
