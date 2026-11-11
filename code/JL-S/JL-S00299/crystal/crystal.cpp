#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[100000],p=1,m1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n);
    long long y[n];
    for(int i=n-1;i>=0;i--){
        p=1;
        m1=m;
        for(int j=0;j<n;j++){
            if(a[i]>=a[j]){
                if(a[i]-a[j]<m1){
                p++;
                m1=m1-a[i]+a[j];
                }
                if(m1==0){
                    break;
                }
            }

        }
        y[i]=p;
    }sort(y,y+n);
    cout<<y[n-1];
    return 0;
}
