#include<bits/stdc++.h>
using namespace std;
long long n[100],d[100],x[100][10000];
int main(){
    int c,t;
    cin>>c>>t;
    if(c==0){
        for(int i=1;i<=t;i++){
            cin>>n[i]>>d[i];
            for(int j=1;j<=n[i];j++){
                cin>>x[i][j];
            }
        }
        for(int i=1;i<=t;i++){
            if(d[i]>=n[i]/2){
                cout<<n[i]-2;
            }
        }
    }

    return 0;
}
