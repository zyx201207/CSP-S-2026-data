#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a[200005];
    int n,m,b=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    b=a[n];
    for(int i=2,j=n-1;i<=m;j--,i++){
        b=b&a[j];
    }
    cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
