#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m.a[1000000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum=max(sum,a[i]&a[j]);
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
