#include<bits/stdc++.h>
using namespace std;
bool cmp(int b,int c){
    return b>c;
}
int main(){
    int n,m,s,a[200005];
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    s=a[1];
    for(int i=2;i<=m;i++){
        s=s&a[i];
    }
    cout<<s;
    return 0;
}

