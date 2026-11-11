#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+3;
int c,t,n,d;
int arr[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i <= n;i++)cin>>arr[i];
        int ch = arr[2]-arr[1];
        if(ch > d){
            cout<<0<<endl;
            return 0;
        }
        else{
            cout<<n-d-1<<endl;
        }
    }
    return 0;
}
