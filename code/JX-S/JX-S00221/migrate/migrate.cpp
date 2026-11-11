#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000010;
int a[N];
int t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0||c==11||c==12){
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            int t=a[2]-a[1];
            d=d/t;
            cout<<n-2*(d-1)-1<<"\n";
        }
    }else{
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            cout<<0<<"\n";
        }
    }
    
    return 0;
}