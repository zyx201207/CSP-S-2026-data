#include<bits/stdc++.h>
using namespace std;
int a[500002];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n<<' '<<m<<' '<<m;
    return 0;
}
