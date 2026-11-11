#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=-1;
int main(){
    freopen("and3.in","r",stdin);
    freopen("and3.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    //for(int i=1;i<=n;i++){
        //int b[200005];
        //int p=15;
        //b[i]=1;
        //for(int j=1;j<=m;j++){
            //if(b[j]==0){
                //b[j]=1;
                //p=p&a[j];
            //}
        //}
        //ans=max(ans,p);
        //cout<<p;
    //}
    cout<<a[n-m+1];
    return 0;
}
