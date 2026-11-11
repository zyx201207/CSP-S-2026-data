#include <bits/stdc++.h>
using namespace std;
int a[1000006];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i-a[i]!=1) flag=false;
    }
    if(flag){
        cout<<n-m;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    long long ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
