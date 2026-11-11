#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int t=-100;
    for(int i=1;i<=n-1;i++){
        if((a[i] and a[i+1])>t)
            t=a[i] and a[i+1];
       // cout<<a[i] and a[i+1];
    }
    cout<<t;
    return 0;
}
