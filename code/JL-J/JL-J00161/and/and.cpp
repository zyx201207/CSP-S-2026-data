#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    long long int n,m;
    cin>>n>>m;
    long long int a[100001];
    for(long long int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

