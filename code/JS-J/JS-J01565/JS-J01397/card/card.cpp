#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        printf("%d ",n);
    }
    return 0;
}