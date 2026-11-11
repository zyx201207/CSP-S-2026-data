#include<bits/stdc++.h>
using namespace  std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[2000005]={},b[2000005]={};
    for(int i=1;i<n;i++){
        cin>>a[i];
        for(int j=i;j<=m;j++){
            a[i]+=b[j];
            a[j=1];
            if(a[i]=b[j])  a[i]++;
            else if(a[i]<b[j]) b[j]-a[i];
            else  b[j]++;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<a[i]<<b[j];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
