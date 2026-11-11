#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2005];
int ans;
int main(){
    cin>>n>>m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }

    else if(m==n){
        ans=a[0];
        for(int i=0;i<n;i++){
            ans=ans&a[i];
        }
    }else if(){
        int x=a[0],y=a[1];
        for(int i=0;i<n-1;i++){
            x=x&a[i];
        }
        for(int i=1;i<n;i++){
            y=y&a[i];
        }ans=max(x,y);
    }else{
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x=a[i]&a[j];
                ans=max(ans,x);
            }
        }
    }
    cout<<ans;
    return 0;
}
