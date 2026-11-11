#include<bits/stdc++.h>
using namespace std;
long long n,m,x=0,gao=0;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1) cout<<a[n-1];
    else if(m==n){
        x=a[0]&a[1];
        for(int i=2;i<n;i++){
            x=x&a[i];
        }
        cout<<x;
    }
    else{
        x=a[n-1]&a[n-2];
        for(int i=n-3;i>=n-m;i--){
            x=x&a[i];
        }
    cout<<x;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
