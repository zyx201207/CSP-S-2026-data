#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, d;
vector<int> a(n+1);
int dp[305][305];
int A[305][305];
void solve(){
    cin>>n>>d;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    if(a[n-1]-a[0]<=d){
        cout<<"0"<<'\n';
        return;
    }
    if(n<4){
        cout<<"0"<<'\n';
        return;
    }
    if(n==4){
        if(a[3]-a[0]>d&&a[1]-a[0]<=d&&a[2]-a[0]<=d&&a[3]-a[1]<=d){
            cout<<"1"<<'\n';
            return;
        }
        else{
            cout<<"0"<<'\n';
            return;
        }
    }
    if(n==5){
        if(a[3]-a[0]>d&&a[4]-a[1]>d&&a[4]-a[2]<=d&&a[3]-a[1]<=d&&a[2]-a[0]<=d){
            cout<<"2"<<'\n';
            return;
        }
        if(a[3]-a[0]>d&&a[4]-a[3]>d&&a[3]-a[1]<=d&&a[2]-a[0]<=d){
            cout<<"1"<<'\n';
            return;
        }
        if(a[4]-a[1]>d&&a[4]-a[2]<=d&&a[3]-a[1]<=d&&a[1]-a[0]>d){
            cout<<"1"<<'\n';
            return;
        }
        else{
            cout<<"0"<<'\n';
            return;
        }
    }
    if(n==6){
        if(a[3]-a[0]>d&&a[4]-a[1]>d&&a[4]-a[2]<=d&&a[3]-a[1]<=d&&a[2]-a[0]<=d&&a[5]-a[4]>d){
            cout<<"2"<<'\n';
            return;
        }
        if(a[3]-a[0]>d&&a[4]-a[1]>d&&a[4]-a[2]<=d&&a[3]-a[1]<=d&&a[2]-a[0]<=d&&a[5]-a[2]>d&&a[5]-a[3]<=d){
            cout<<"3"<<'\n';
            return;
        }
        if(a[3]-a[0]>d&&a[4]-a[3]>d&&a[3]-a[1]<=d&&a[2]-a[0]<=d){
            cout<<"1"<<'\n';
            return;
        }
         if(a[4]-a[1]>d&&a[4]-a[2]<=d&&a[3]-a[1]<=d&&a[1]-a[0]>d&&a[5]-a[2]>d&&a[5]-a[3]<=d){
            cout<<"2"<<'\n';
            return;
        }
        else{
            cout<<"0"<<'\n';
            return;
        }
    }
}

signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","W",stdout);

    int c, t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
