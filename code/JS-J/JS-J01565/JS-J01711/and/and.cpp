#include <bits/stdc++.h>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,f);
    int s=a[0];
    for(int i=1;i<m;i++){
        s&=a[i];
    }
    cout<<s;
    return 0;
}
