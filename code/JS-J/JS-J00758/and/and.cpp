#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;//attention to the size of N!
int a[N],dp[N];
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m]<<"\n";
    //cout<<dp[m]<<"\n";
}