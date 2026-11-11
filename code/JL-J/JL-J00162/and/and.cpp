#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(m==1)cout<<a[n-1];
    else if(m==2){
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
    }
    else if(m==n-1){
        int x=a[1];
        for(int i=2;i<n;i++){
            x=x&a[i];
        }
        cout<<x;
    }
    else if(m==n){
        int x=a[0];
        for(int i=1;i<n;i++){
            x=x&a[i];
        }
        cout<<x;
    }
    else cout<<31;
    return 0;
}
