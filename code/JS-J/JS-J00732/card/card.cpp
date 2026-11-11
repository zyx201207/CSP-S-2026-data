#include <bits/stdc++.h>
using namespace std;

int a[500010];
int l[300010];
int s[500010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        s[l[a[i]]]+=s[i-1]+1;
    }
    for(int i=1;i<=m;i++){
        printf("%d ",s[l[i]]);
    }
    return 0;
}
