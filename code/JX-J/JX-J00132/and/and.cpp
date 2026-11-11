#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    long long  n,m,a[200005]={},yu=0,b[200005]={},p=0,bj[200005]={};
    string s;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        yu=a[i];
        while(yu!=0){
            p++;
            b[p]=yu%2;
            cout<<b[p];
            yu/=2;
        }
        bj[i]=p;
    }
    long long c[200005]={};
    for(int i=1;i<=n;i++){
        for(int j=bj[i];j>=bj[i-1];j--){
            c[i]=b[j];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<c[i];
    }
    return 0;
}
