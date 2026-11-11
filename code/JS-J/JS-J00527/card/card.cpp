#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        t[i]=i;
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                t[i]=t[j];
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            ans[a[j]]++;
            j=t[j]+1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
//g++ card.cpp -o card -std=c++11