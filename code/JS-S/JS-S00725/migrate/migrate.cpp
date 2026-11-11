#include<bits/stdc++.h>
using namespace std;
int a[2000005];
bool check(int n){
    int x=a[1]-a[0];
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]!=x)return false;
    }return true;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,q;
    cin>>c>>q;
    while(q--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)cin>>a[i];
        if(check(n)){
            int ans=0;
            if(d>=2*(a[1]-a[0])) ans=max(ans,n-(2*(d/(a[1]-a[0]))-1));
        cout<<ans<<endl;
        }
        cout<<0<<"\n";
    }
}
