#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],s[500001],maxx=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n<2){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n);
    if(n>=5000){
        int x=a[2]-a[1];
        for(int i=1;;i++){
            m-=i*x;
            if(m<0){
                cout<<i-1;
                return 0;
            }
        }
    }
    s[0]=0;
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        s[i]=s[i-1]+b[i];
    }
    for(int l=1,r=1;r<n;r++){
        for(;l<=r;l++){
            if(s[r]-s[l-1]<=m)break;
        }
        if(s[r]-s[l-1]<=m){
            maxx=max(maxx,r-l+1);
        }
    }
    cout<<maxx+1;
    return 0;
}
