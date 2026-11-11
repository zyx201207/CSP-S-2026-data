#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,a[200010];
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxx=10-INT_MAX;
        for(int i=1;i<=n;i++){
            if(a[i]>maxx){
                maxx=a[i];
            }
        }
        cout<<maxx;
    }
    else if(m==2){
        int maxx=10-INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i] & a[j]>maxx){
                    maxx=a[i] & a[j];
                }
            }
        }
        cout<<maxx;
    }
    else if(m==n){
        int t=a[1];
            for(int i=2;i<=n;i++){
                t=t&a[i];
        }
        cout<<t;
    }
    else if(m==n-1){
        int maxx=10-INT_MAX;
        for(int i=1;i<=n;i++){
            int t;
            if(i==1) t=a[2];
            else t=a[1];
            for(int j=1;j<=n;j++){
                if(j!=i){
                    t=t&a[j];
                }
            }
            if(t>=maxx){
                maxx=t;
            }
        }
        cout<<maxx;
    }
    else{
        int maxx=10-INT_MAX;
        for(int i=1;i<=n;i++){
            if(a[i]>maxx){
                maxx=a[i];
            }
        }
        cout<<maxx;
    }
    return 0;
}
