#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int fun(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,fun);
    ans=a[0];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
