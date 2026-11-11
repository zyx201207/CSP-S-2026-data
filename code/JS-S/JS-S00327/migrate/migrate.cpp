#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
        while(t--){
            int n,d;
            cin>>n>>d;
            int a[222222];
            for(int i=1;i<=n;i++)cin>>a[i];
            int x=a[2]-a[1];
            if(d<=x||d==1)cout<<"0";
            else{
                d*=2;
                if(n>=d)cout<<n-d+1;
                else cout<<"0";
            }
            cout<<endl;
        }
    return 0;
}
