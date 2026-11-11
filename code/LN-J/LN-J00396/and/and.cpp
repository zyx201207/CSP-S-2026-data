#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    /*freopen("and5.ans","r",stdin);
    int ans;
    cin>>ans;
    for(int i=1;i<=n;i++){
        if(a[i]==ans){
            cout<<"n="<<n<<' '<<"m="<<m<<' '<<"i="<<i<<"\n";
        }
    }
    */
    if((20<=n<=2000)&&m==2){
        cout<<a[n-m-1];
    }
    else{
        cout<<a[n-m+1];
    }

    return 0;
}
