#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,a[1000000],m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i,t=0;
    for(i=0;i<m;i++){
        a[t]=a[t-n]&a[t+1-n];
        for(int j=1;j<n-1-i;j++){
            a[t+j]=max(a[t+i-n],a[t+i-n]&a[t+i+1-n]);
            cout<<a[t+j]<<" ";
        }
        cout<<endl;
        t+=n;
    }
    long long maxx=a[0];
    for(int j=1;j<i;j++){
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
    return 0;
}
