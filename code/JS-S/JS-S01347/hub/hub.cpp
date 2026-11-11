#include<bits/stdc++.h>
using namespace std;

int main(){

    int c,t;
    cin>>c>>t;

    long long n[10],k[10],u[10][10],v[10][10];
    for(int i=1;i<=t;i++){
        cin>>n[i]>>k[i];
        for(int j=1;j<=n[i]-1;j++){
            cin>>u[i][j]>>v[i][j];
        }
    }

    long long r[10];
    for(int i=1;i<=t;i++){
        cout<<r[i]<<endl;
    }

    return 0;
}
