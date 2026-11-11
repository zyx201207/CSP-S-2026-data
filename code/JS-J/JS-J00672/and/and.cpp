#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    long long a[100086];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long maxx=LLONG_MIN;
    if(m==n){
        int ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    for(int i=0;i<n;i++){
        long long res;
        long long q[100086]={a[i]};
        for(int j=1;j<m;j++){
            q[m-j]=a[n-i-j];
        }
        res=q[0];
        for(int j=1;j<m;j++){
            res=res&q[j];
        }
        if(res>=maxx)maxx=res;
    }
    cout<<maxx;
    return 0;
}
