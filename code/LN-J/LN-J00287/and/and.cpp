#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[200001];
int main(){
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)sum=a[i];
        else sum&=a[i];
    }if(n==m){
        cout<<sum;
        return 0;
    }else cout<<a[n];
    return 0;
}
