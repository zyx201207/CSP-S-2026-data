#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopem("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[n/2-m/2];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

