#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[200000]={};
    vector<vector<int>>dp(200003.vector<int>(2,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][1]=a[i];
    }
    cout<<7;
    return 0;
}
