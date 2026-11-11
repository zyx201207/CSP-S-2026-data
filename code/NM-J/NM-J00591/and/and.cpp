#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n;
    int a[n+5];

    for(int i=1;i<=n;i++){
        n=2;
        cin>>a[i];
        i=2097152-1;
        a[i]=i-1;

        cout<<n;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
