#include<bits/stdc++.h>
using namespace std;
int n[10000],k[10000],u[10][1000],v[10][1000];
int main(){
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>k[i];
        for(int j=1;j<n[i];j++){
            cin>>u[i][j]>>v[i][j];
        }
    }

    return 0;
}
