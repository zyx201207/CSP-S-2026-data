#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005];
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int cnt=1;
    for (int i=1;i<=m;i++){
        if (i==1)
            cnt=a[i];
        cnt=(cnt&a[i]);
    }
    cout<<cnt;
    return 0;
}
