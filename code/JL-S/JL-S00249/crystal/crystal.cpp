#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N];
bool b[N];
int n,m,ans;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(b[i]==1) continue;
        for(int k=1;k<=m;k++){
            if(a[i]==a[i+k]){
            ans++;
            b[i]=b[i+m]=1;
            continue;
            }
        }


    for(int j=1;j<=m;j++){
        for(int k=1;k<=m;k++){
            if(a[i]+j==a[i+k]){
                ans++;
                b[i]=b[i+k]=1;

            }
        }
    }
    }
    cout<<ans;
    return 0;
}
//RP++
