#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n%2==1){
        cout<<a[n/2+1];
    }else{
        cout<<a[n/2];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
