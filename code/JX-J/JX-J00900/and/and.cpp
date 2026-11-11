#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int maxx=15;
    for(int i=1;i<=m;i++){
        maxx=(maxx&a[i]);

    }

    cout<<maxx;
    return 0;
}
