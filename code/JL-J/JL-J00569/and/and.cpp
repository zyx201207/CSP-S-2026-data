#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    int sum=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1] && i>1){
            sum++;
        }
        if(sum==m){
            cout<<a[i];
            return 0;
        }
        if(a[i]!=a[i-1] && i>1){
            sum=0;
        }
    }
    cout<<a[(n+1)/2];
    return 0;
}

