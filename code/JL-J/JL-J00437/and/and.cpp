#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]){
            sum=a[i];
        }
    }
    cout<<sum;
    return 0;
}
