#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[1000000] = {0};
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    cout<<a[m];





    return 0;
}
