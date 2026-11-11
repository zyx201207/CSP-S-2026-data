#include<bits/stdc++.h>
using namespace std;
int a[100086];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(long long int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
